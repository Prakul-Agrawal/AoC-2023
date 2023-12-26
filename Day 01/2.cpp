//
// Created by Prakul Agrawal on 12/2/23.
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
    ll total = 0;
    map <string, int> m;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    int index;
    while(1) {
        cin >> s;
        if (s == "EOF") {
            break;
        }
        int first_digit = -1, last_digit = -1;
        int first_index = -1, last_index = -1;
        rep(i, 0, sz(s)) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (first_digit == -1) {
                    first_digit = s[i] - '0';
                    first_index = i;
                }
                last_digit = s[i] - '0';
                last_index = i;
            }
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            if ((index = s.find(it->first)) != string::npos) {
                if (index < first_index) {
                    first_digit = it->second;
                    first_index = index;
                }
            }
            if ((index = s.rfind(it->first)) != string::npos) {
                if (index > last_index) {
                    last_digit = it->second;
                    last_index = index;
                }
            }
        }
        total += first_digit * 10 + last_digit;
    }
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
//    tc solve();
    solve();
}