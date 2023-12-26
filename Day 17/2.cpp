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

void solve() {
    vvi grid;
    string s;
    while (getline(cin, s)) {
        vi row;
        for (char c : s) {
            row.pb(c - '0');
        }
        grid.pb(row);
    }
    int n = sz(grid);
    int m = sz(grid[0]);
    vvi dist(n, vi(m, INT_MAX));
    min_heap(vi) pq;
    map<vi, int> visited;
    // first is cost, second is count, third is y, fourth is x, fifth is dy, sixth is dx
    pq.push({0, 1, 0, 0, 1, 0});
    pq.push({0, 1, 0, 0, 0, 1});
    while (!pq.empty()) {
        vi curr = pq.top();
        pq.pop();
        int cost = curr[0];
        int count = curr[1];
        int y = curr[2];
        int x = curr[3];
        int dy = curr[4];
        int dx = curr[5];
        y += dy;
        x += dx;
        if (y < 0 || y >= n || x < 0 || x >= m) {
            continue;
        }
        if (visited[{count, y, x, dy, dx}]) {
            continue;
        }
        visited[{count, y, x, dy, dx}] = 1;
        cost += grid[y][x];
        if (y == n - 1 && x == m - 1 && count >= 4) {
            cout << cost << endl;
            return;
        }
        if (count < 4) {
            pq.push({cost, count + 1, y, x, dy, dx});
        }
        else {
            pq.push({cost, 1, y, x, -dx, dy});
            pq.push({cost, 1, y, x, dx, -dy});
            if (count != 10) {
                pq.push({cost, count + 1, y, x, dy, dx});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}