//
// Created by Prakul Agrawal on 12/22/23.
//

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<vii> vvii;
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define all(s) s.begin(), s.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define printcase int t; cin>>t; for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";solve();}
#define max_heap(x) priority_queue<x>
#define min_heap(x) priority_queue<x, vector<x>, greater<x>>

void solve() {
    map<string, int> indexMap;
    vi numCond, preSumNumCond, symbol, cmpValue;
    vector<string> destName;
    vector<char> cond;
    string s, name;
    int index = 0;
    while(getline(cin, s)) {
        if(s == "") break;
        int nameLength = s.find('{');
        name = s.substr(0, nameLength);
        indexMap[name] = index++;
        s = s.substr(nameLength + 1, s.length() - nameLength - 2);
        int pos = 0, count = 0;
        while(true) {
            bool isLast = false;
            if ((pos = s.find(',')) == string::npos)
                isLast = true;
            count++;
            string token = s.substr(0, pos);
            int colonPos = token.find(':');
            if(colonPos == string::npos) {
                cond.pb(' ');
                symbol.pb(0);
                cmpValue.pb(0);
                destName.pb(token);
            }
            else {
                cond.pb(token[0]);
                if (token[1] == '>')
                    symbol.pb(1);
                else
                    symbol.pb(-1);
                cmpValue.pb(stoi(token.substr(2, colonPos - 2)));
                destName.pb(token.substr(colonPos + 1));
            }
            if(isLast) break;
            s.erase(0, pos + 1);
        }
        numCond.pb(count);
    }
    preSumNumCond.pb(0);
    rep(i, 0, numCond.size()) {
        preSumNumCond.pb(preSumNumCond[i] + numCond[i]);
    }
    map<char, int> parts;
    ll total = 0;
    while(getline(cin, s)) {
        char chr, temp;
        int num;
        istringstream iss(s);
        iss >> temp;
        rep(i, 0, 4) {
            iss >> chr;
            iss >> temp;
            iss >> num;
            iss >> temp;
            parts[chr] = num;
        }
        name = "in";
        while(true) {
            int ind = indexMap[name];
            int num = numCond[ind];
            int preSum = preSumNumCond[ind];
            rep(i, 0, num) {
                char c = cond[preSum + i];
                int sym = symbol[preSum + i];
                int cmp = cmpValue[preSum + i];
                string dest = destName[preSum + i];
                if (c == ' ') {
                    name = dest;
                    break;
                }
                int val = parts[c];
                if (sym == 1 && val > cmp) {
                    name = dest;
                    break;
                }
                else if (sym == -1 && val < cmp) {
                    name = dest;
                    break;
                }
            }
            if (name == "A") {
                for (auto p : parts)
                    total += p.ss;
                break;
            }
            if (name == "R")
                break;
        }
    }
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}