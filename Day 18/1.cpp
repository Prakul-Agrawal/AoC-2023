//
// Created by Prakul Agrawal on 12/21/23.
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

void floodFill(vvi &grid, int i, int j, int val) {
    if (i < 0 || i >= sz(grid) || j < 0 || j >= sz(grid[0])) {
        return;
    }
    if (grid[i][j] == 1 || grid[i][j] == 2) {
        return;
    }
    grid[i][j] = val;
    floodFill(grid, i + 1, j, val);
    floodFill(grid, i - 1, j, val);
    floodFill(grid, i, j + 1, val);
    floodFill(grid, i, j - 1, val);
}

void solve() {
    vector<pair<char, pair<int, string>>> plan;
    string s;
    int maxRight = 0, minLeft = 0, minUp = 0, maxDown = 0;
    int horizontal = 0, vertical = 0;
    while (getline(cin, s)) {
        istringstream iss(s);
        char dir;
        int steps;
        string color;
        iss >> dir >> steps >> color;
        plan.pb({dir, {steps, color}});
        if (dir == 'R') {
            horizontal += steps;
            maxRight = max(maxRight, horizontal);
        } else if (dir == 'L') {
            horizontal -= steps;
            minLeft = min(minLeft, horizontal);
        } else if (dir == 'U') {
            vertical -= steps;
            minUp = min(minUp, vertical);
        } else if (dir == 'D') {
            vertical += steps;
            maxDown = max(maxDown, vertical);
        }
    }
    vvi grid(maxDown - minUp + 1, vi(maxRight - minLeft + 1, 0));
    int n = sz(grid);
    int m = sz(grid[0]);
    map<char, pii> dirMap;
    dirMap['R'] = {1, 0};
    dirMap['L'] = {-1, 0};
    dirMap['U'] = {0, -1};
    dirMap['D'] = {0, 1};
    int x = -minLeft, y = -minUp;
    for (auto p : plan) {
        int steps = p.ss.ff;
        char dir = p.ff;
        pii dirVec = dirMap[dir];
        rep(i, 0, steps) {
            x += dirVec.ff;
            y += dirVec.ss;
            grid[y][x] = 1;
        }
    }
    rep(i, 0, m) {
        floodFill(grid, 0, i, 2);
        floodFill(grid, n - 1, i, 2);
    }
    rep(i, 0, n) {
        floodFill(grid, i, 0, 2);
        floodFill(grid, i, m - 1, 2);
    }
    ll ans = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (grid[i][j] != 2) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}