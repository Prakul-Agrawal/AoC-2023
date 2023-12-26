//
// Created by Prakul Agrawal on 12/24/23.
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
    vector<string> grid;
    string s;
    while (getline(cin, s)) {
        grid.pb(s);
    }
    int n = sz(grid);
    int m = sz(grid[0]);
    int len = n;
    int x = -1, y = -1;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (grid[i][j] == 'S') {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1) {
            break;
        }
    }
    x += 3 * n;
    y += 3 * m;
    vector<string> newGrid;
    rep(i, 0, n) {
        string newString = "";
        rep(j, 0, 7) {
            newString += grid[i];
        }
        newGrid.pb(newString);
    }
    rep(i, 0, 6) {
        rep(j, 0, n) {
            newGrid.pb(newGrid[j]);
        }
    }
    ll num = 26501365;
    ll r = num % n;

    n = sz(newGrid);
    m = sz(newGrid[0]);
    grid = newGrid;

    vvi dist(n, vi(m, -1));
    queue<pii> distQueue;
    distQueue.push({x, y});
    dist[x][y] = 0;
    while (!distQueue.empty()) {
        pii curr = distQueue.front();
        distQueue.pop();
        int i = curr.ff;
        int j = curr.ss;
        int newDist = dist[i][j] + 1;
        if (i > 0 && grid[i - 1][j] != '#' && dist[i - 1][j] == -1) {
            dist[i - 1][j] = newDist;
            distQueue.push({i - 1, j});
        }
        if (i < n - 1 && grid[i + 1][j] != '#' && dist[i + 1][j] == -1) {
            dist[i + 1][j] = newDist;
            distQueue.push({i + 1, j});
        }
        if (j > 0 && grid[i][j - 1] != '#' && dist[i][j - 1] == -1) {
            dist[i][j - 1] = newDist;
            distQueue.push({i, j - 1});
        }
        if (j < m - 1 && grid[i][j + 1] != '#' && dist[i][j + 1] == -1) {
            dist[i][j + 1] = newDist;
            distQueue.push({i, j + 1});
        }
    }
    vll values(3, 0);
    rep(i, 0, 3) {
        int steps = r + (i + 1) * len;
        rep(j, 0, n) {
            rep(k, 0, m) {
                int foundDist = dist[j][k];
                if (foundDist != -1 && foundDist <= steps && foundDist % 2 == steps % 2) {
                    values[i]++;
                }
            }
        }
    }
    // Using Lagrange Interpolation
    ll ans = 0;
    vll steps;
    rep(i, 0, 3) {
        steps.pb(r + (i + 1) * len);
    }
    ans += (num - steps[1]) * (num - steps[2]) / ((steps[0] - steps[1]) * (steps[0] - steps[2])) * values[0];
    ans += (num - steps[0]) * (num - steps[2]) / ((steps[1] - steps[0]) * (steps[1] - steps[2])) * values[1];
    ans += (num - steps[0]) * (num - steps[1]) / ((steps[2] - steps[0]) * (steps[2] - steps[1])) * values[2];
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}