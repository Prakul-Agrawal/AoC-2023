//
// Created by Prakul Agrawal on 12/20/23.
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

vector<vvi> visited;
int n, m;

void dfs(vector<string> &grid, char dir, int x, int y) {
    int dirValue;
    if (dir == 'R')
        dirValue = 0;
    else if (dir == 'L')
        dirValue = 1;
    else if (dir == 'U')
        dirValue = 2;
    else if (dir == 'D')
        dirValue = 3;
    if (visited[x][y][dirValue] == 1)
        return;
    visited[x][y][dirValue] = 1;
    char curr = grid[x][y];
    if (dir == 'R') {
        if (curr == '.' || curr == '-') {
            if (y + 1 < m)
                dfs(grid, 'R', x, y + 1);
        }
        else if (curr == '|') {
            if (x - 1 >= 0)
                dfs(grid, 'U', x - 1, y);
            if (x + 1 < n)
                dfs(grid, 'D', x + 1, y);
        }
        else if (curr == '/') {
            if (x - 1 >= 0)
                dfs(grid, 'U', x - 1, y);
        }
        else if (curr == '\\') {
            if (x + 1 < n)
                dfs(grid, 'D', x + 1, y);
        }
    }
    else if (dir == 'L') {
        if (curr == '.' || curr == '-') {
            if (y - 1 >= 0)
                dfs(grid, 'L', x, y - 1);
        }
        else if (curr == '|') {
            if (x - 1 >= 0)
                dfs(grid, 'U', x - 1, y);
            if (x + 1 < n)
                dfs(grid, 'D', x + 1, y);
        }
        else if (curr == '/') {
            if (x + 1 < n)
                dfs(grid, 'D', x + 1, y);
        }
        else if (curr == '\\') {
            if (x - 1 >= 0)
                dfs(grid, 'U', x - 1, y);
        }
    }
    else if (dir == 'U') {
        if (curr == '.' || curr == '|') {
            if (x - 1 >= 0)
                dfs(grid, 'U', x - 1, y);
        }
        else if (curr == '-') {
            if (y - 1 >= 0)
                dfs(grid, 'L', x, y - 1);
            if (y + 1 < m)
                dfs(grid, 'R', x, y + 1);
        }
        else if (curr == '/') {
            if (y + 1 < m)
                dfs(grid, 'R', x, y + 1);
        }
        else if (curr == '\\') {
            if (y - 1 >= 0)
                dfs(grid, 'L', x, y - 1);
        }
    }
    else if (dir == 'D') {
        if (curr == '.' || curr == '|') {
            if (x + 1 < n)
                dfs(grid, 'D', x + 1, y);
        }
        else if (curr == '-') {
            if (y - 1 >= 0)
                dfs(grid, 'L', x, y - 1);
            if (y + 1 < m)
                dfs(grid, 'R', x, y + 1);
        }
        else if (curr == '/') {
            if (y - 1 >= 0)
                dfs(grid, 'L', x, y - 1);
        }
        else if (curr == '\\') {
            if (y + 1 < m)
                dfs(grid, 'R', x, y + 1);
        }
    }
}

void solve() {
    vector<string> grid;
    string s;
    while (getline(cin, s)) {
        grid.pb(s);
    }
    n = sz(grid);
    m = sz(grid[0]);
    rep(i, 0, n) {
        vvi temp;
        rep(j, 0, m) {
            vi tempDir(4, 0);
            temp.pb(tempDir);
        }
        visited.pb(temp);
    }
    dfs(grid, 'R', 0, 0);
    ll ans = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (visited[i][j][0] == 1 || visited[i][j][1] == 1 || visited[i][j][2] == 1 || visited[i][j][3] == 1)
                ans++;
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