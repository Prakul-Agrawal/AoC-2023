//
// Created by Prakul Agrawal on 12/19/23.
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
    string s;
    getline(cin, s);
    istringstream iss(s);
    vector<string> tokens;
    string token;
    while (getline(iss, token, ',')) {
        tokens.push_back(token);
    }
    vector<vector<pair<string, int>>> hashmap(256);
    for(auto str: tokens) {
        int minusPos = str.find('-');
        if (minusPos != string::npos) {
            int length = str.length() - 1;
            str = str.substr(0, minusPos);
            int curr = 0;
            rep(i, 0, length) {
                curr += str[i];
                curr *= 17;
                curr %= 256;
            }
            length = sz(hashmap[curr]);
            rep(i, 0, length) {
                if (hashmap[curr][i].ff == str) {
                    hashmap[curr][i].ff = "";
                    break;
                }
            }
        }
        else {
            int length = str.length()-2;
            int focus = str[str.length() - 1] - '0';
            str = str.substr(0, str.length() - 2);
            int curr = 0;
            rep(i, 0, length) {
                curr += str[i];
                curr *= 17;
                curr %= 256;
            }
            length = sz(hashmap[curr]);
            bool found = false;
            rep(i, 0, length) {
                if (hashmap[curr][i].ff == str) {
                    hashmap[curr][i].ss = focus;
                    found = true;
                    break;
                }
            }
            if (!found) {
                hashmap[curr].pb({str, focus});
            }
        }
    }
    ll total = 0;
    rep(box, 0, 256) {
        int count = 0;
        for (auto lens: hashmap[box]) {
            if (lens.ff != "") {
                total += (box + 1) * (++count) * lens.ss;
            }
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