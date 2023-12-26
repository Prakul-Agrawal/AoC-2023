//
// Created by Prakul Agrawal on 12/11/23.
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
//#define endl '\n'
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
    vector<string> v;
    while(1) {
        getline(cin, s);
        if (s == "EOF") {
            break;
        }
        v.pb(s);
    }
    int height = sz(v), width = sz(v[0]);

    set <pii> symbol_pos;
    rep(i, 0, height) {
        rep(j, 0, width) {
            if (v[i][j] != '.' && (v[i][j] < '0' || v[i][j] > '9')) {
                symbol_pos.insert({i, j});
            }
        }
    }

    set <pii> number_pos;
    for (auto i : symbol_pos) {
        int x = i.ff, y = i.ss;
        if (x > 0) {
            if (y > 0) {
                if (v[x-1][y-1] >= '0' && v[x-1][y-1] <= '9') {
                    number_pos.insert({x-1, y-1});
                }
            }
            if (y < width-1) {
                if (v[x-1][y+1] >= '0' && v[x-1][y+1] <= '9') {
                    number_pos.insert({x-1, y+1});
                }
            }
            if (v[x-1][y] >= '0' && v[x-1][y] <= '9') {
                number_pos.insert({x-1, y});
            }
        }
        if (x < height-1) {
            if (y > 0) {
                if (v[x+1][y-1] >= '0' && v[x+1][y-1] <= '9') {
                    number_pos.insert({x+1, y-1});
                }
            }
            if (y < width-1) {
                if (v[x+1][y+1] >= '0' && v[x+1][y+1] <= '9') {
                    number_pos.insert({x+1, y+1});
                }
            }
            if (v[x+1][y] >= '0' && v[x+1][y] <= '9') {
                number_pos.insert({x+1, y});
            }
        }
        if (y > 0) {
            if (v[x][y-1] >= '0' && v[x][y-1] <= '9') {
                number_pos.insert({x, y-1});
            }
        }
        if (y < width-1) {
            if (v[x][y+1] >= '0' && v[x][y+1] <= '9') {
                number_pos.insert({x, y+1});
            }
        }
    }

    ll current_number = 0;
    bool include_number = false;
    rep(i, 0, height) {
        rep(j, 0, width) {
            if (v[i][j] >= '0' && v[i][j] <= '9') {
                current_number = current_number * 10 + (v[i][j] - '0');
                if (number_pos.find({i, j}) != number_pos.end()) {
                    include_number = true;
                }
            } else {
                if (include_number) {
                    total += current_number;
                    include_number = false;
                }
                current_number = 0;
            }
        }
        if (include_number) {
            total += current_number;
            include_number = false;
        }
        current_number = 0;
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