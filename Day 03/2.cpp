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
#define endl '\n'
#define all(s) s.begin(), s.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define printcase int t; cin>>t; for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";solve();}
#define max_heap(x) priority_queue<x>
#define min_heap(x) priority_queue<x, vector<x>, greater<x>>

bool update_numbers(int &count, ll &number_1, ll &number_2, ll value) {
    count++;
    if (count == 1) {
        number_1 = value;
    }
    else if (count == 2) {
        number_2 = value;
    }
    else {
        number_1 = number_2 = 0;
        count = 0;
        return false;
    }
    return true;
}

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
            if (v[i][j] == '*') {
                symbol_pos.insert({i, j});
            }
        }
    }

    ll current_number = 0;
    vector<vll> pos_value(height, vll(width, 0));
    int start = -1, end = -1;
    rep(i, 0, height) {
        rep(j, 0, width) {
            if (v[i][j] >= '0' && v[i][j] <= '9') {
                current_number = current_number * 10 + (v[i][j] - '0');
                if (start == -1) {
                    start = j;
                }
                end = j;
            }
            else {
                if (start != -1) {
                    rep(k, start, end+1) {
                        pos_value[i][k] = current_number;
                    }
                    start = -1;
                    end = -1;
                    current_number = 0;
                }
            }
        }
        if (start != -1) {
            rep(k, start, end+1) {
                pos_value[i][k] = current_number;
            }
            start = -1;
            end = -1;
            current_number = 0;
        }
    }

    ll number_1 = 0, number_2 = 0;
    bool continuous_1 = false, continuous_2 = false;
    int count = 0;
    for (auto i : symbol_pos) {
        int x = i.ff, y = i.ss;
        number_1 = number_2 = 0;
        continuous_1 = continuous_2 = false;
        count = 0;
        if (x > 0) {
            if (v[x-1][y] >= '0' && v[x-1][y] <= '9') {
                continuous_1 = true;
                if (!update_numbers(count, number_1, number_2, pos_value[x-1][y])) {
                    continue;
                }
            }
            if (!continuous_1) {
                if (y > 0) {
                    if (v[x-1][y-1] >= '0' && v[x-1][y-1] <= '9' && !update_numbers(count, number_1, number_2, pos_value[x-1][y-1])) {
                        continue;
                    }
                }
                if (y < width-1) {
                    if (v[x-1][y+1] >= '0' && v[x-1][y+1] <= '9' && !update_numbers(count, number_1, number_2, pos_value[x-1][y+1])) {
                        continue;
                    }
                }

            }
        }
        if (x < height-1) {
            if (v[x+1][y] >= '0' && v[x+1][y] <= '9') {
                continuous_2 = true;
                if (!update_numbers(count, number_1, number_2, pos_value[x+1][y])) {
                    continue;
                }
            }
            if (!continuous_2) {
                if (y > 0) {
                    if (v[x+1][y-1] >= '0' && v[x+1][y-1] <= '9' && !update_numbers(count, number_1, number_2, pos_value[x+1][y-1])) {
                        continue;
                    }
                }
                if (y < width-1) {
                    if (v[x+1][y+1] >= '0' && v[x+1][y+1] <= '9' && !update_numbers(count, number_1, number_2, pos_value[x+1][y+1])) {
                        continue;
                    }
                }
            }
        }
        if (y > 0) {
            if (v[x][y-1] >= '0' && v[x][y-1] <= '9' && !update_numbers(count, number_1, number_2, pos_value[x][y-1])) {
                continue;
            }
        }
        if (y < width-1) {
            if (v[x][y+1] >= '0' && v[x][y+1] <= '9' && !update_numbers(count, number_1, number_2, pos_value[x][y+1])) {
                continue;
            }
        }
        if (count == 2) {
            total += number_1 * number_2;
        }
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