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

map<string, int> indexMap;
vi numCond, preSumNumCond, symbol, cmpValue;
vector<string> destName;
vector<char> cond;
map<char, int> condMap({{'x', 0}, {'m', 2}, {'a', 4}, {'s', 6}});
ll total = 0;

void testInterval(ll interval[8], string name, int condNum) {
    int ind = indexMap[name];
    int num = numCond[ind];
    int preSum = preSumNumCond[ind];
    char c = cond[preSum + condNum];
    int sym = symbol[preSum + condNum];
    int cmp = cmpValue[preSum + condNum];
    string dest = destName[preSum + condNum];
    if (c == ' ') {
        if (dest == "A") {
            total += (interval[1] - interval[0] + 1) * (interval[3] - interval[2] + 1) *
                     (interval[5] - interval[4] + 1) * (interval[7] - interval[6] + 1);
        }
        else if (dest != "R") {
            testInterval(interval, dest, 0);
        }
        return;
    }
    ll lower = interval[condMap[c]], upper = interval[condMap[c] + 1];
    ll acceptedInterval[8], rejectedInterval[8];
    rep(i, 0, 8) {
        acceptedInterval[i] = interval[i];
        rejectedInterval[i] = interval[i];
    }
    bool isAccepted = false, isRejected = false;
    if (sym == 1) {
        if (lower > cmp) {
            isAccepted = true;
        }
        else if (upper <= cmp) {
            isRejected = true;
        }
        else {
            acceptedInterval[condMap[c]] = cmp + 1;
            rejectedInterval[condMap[c] + 1] = cmp;
            isAccepted = true;
            isRejected = true;
        }
    }
    else if (sym == -1) {
        if (upper < cmp) {
            isAccepted = true;
        }
        else if (lower >= cmp) {
            isRejected = true;
        }
        else {
            acceptedInterval[condMap[c] + 1] = cmp - 1;
            rejectedInterval[condMap[c]] = cmp;
            isAccepted = true;
            isRejected = true;
        }
    }
    if (isRejected) {
        testInterval(rejectedInterval, name, condNum + 1);
    }
    if (isAccepted) {
        if (dest == "A") {
            total += (acceptedInterval[1] - acceptedInterval[0] + 1) * (acceptedInterval[3] - acceptedInterval[2] + 1) *
                     (acceptedInterval[5] - acceptedInterval[4] + 1) * (acceptedInterval[7] - acceptedInterval[6] + 1);
        } else if (dest != "R") {
            testInterval(acceptedInterval, dest, 0);
        }
    }
}

void solve() {
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
    while(getline(cin, s)) {}
    ll initialInterval[8] = {1, 4000, 1, 4000, 1, 4000, 1, 4000};
    testInterval(initialInterval, "in", 0);
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}