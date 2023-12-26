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

int n, m;

void runCycle(vector<string> &grid) {
    rep(_, 0, 2){
        rep(i, 0, m) {
            int pos = 0;
            rep(j, 0, n) {
                if (grid[j][i] == 'O') {
                    grid[j][i] = '.';
                    grid[pos][i] = 'O';
                    pos++;
                }
                else if (grid[j][i] == '#') {
                    pos = j + 1;
                }
            }
        }
        rep(i, 0, n) {
            int pos = 0;
            rep(j, 0, m) {
                if (grid[i][j] == 'O') {
                    grid[i][j] = '.';
                    grid[i][pos] = 'O';
                    pos++;
                } else if (grid[i][j] == '#') {
                    pos = j + 1;
                }
            }
        }
        rep(i, 0, n / 2) {
            rep(j, 0, m) {
                swap(grid[i][j], grid[n - i - 1][m - j - 1]);
            }
        }
        if (n % 2 == 1) {
            rep(j, 0, m / 2) {
                swap(grid[n / 2][j], grid[n / 2][m - j - 1]);
            }
        }
    }
}

void solve() {
    vector<string> grid;
    string s;
    map<string, ll> visitedGrids;

    while (getline(cin, s)) {
        grid.push_back(s);
    }

    n = sz(grid);
    m = sz(grid[0]);

    ll count = 0;
    string currentGridStr = accumulate(grid.begin(), grid.end(), string(""));
    visitedGrids[currentGridStr] = 0;

    while (true) {
        count++;
        runCycle(grid);
        currentGridStr = accumulate(grid.begin(), grid.end(), string(""));
        if (visitedGrids.count(currentGridStr) > 0) {
            break;
        }
        visitedGrids[currentGridStr] = count;
    }

    ll initialIndex = visitedGrids[currentGridStr];
    ll cycleLength = count - initialIndex;
    ll remainingCycles = (1000000000 - initialIndex) % cycleLength;

    for (ll i = 0; i < remainingCycles; ++i) {
        runCycle(grid);
    }

    ll total = 0;
    rep(i, 0, m) {
        rep(j, 0, n) {
            if (grid[j][i] == 'O') {
                total += n - j;
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