//
// Created by Prakul Agrawal on 12/25/23.
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

vector<string> grid;
vvi visited;
map<pii, int> junctionIndex;
set<pii> junctions;
set<pair<int, pii>> edges;
int id;

int longest = 0;
vi newVisited;

void newDFS(int node, vvii &adj, int length) {
//    cout << "Node: " << node << " Length: " << length << endl;
    newVisited[node] = 1;
    if (node == 1) {
        longest = max(longest, length);
    }
    else {
        for (auto edge : adj[node]) {
            if (newVisited[edge.ff] == 0) {
                newDFS(edge.ff, adj, length + edge.ss);
            }
        }
    }
    newVisited[node] = 0;
}

void dfs(int x, int y, int prevIndex, bool forwardEdge, int edgeLength) {
//    cout << "Checking: " << x << " " << y << endl;
    if (grid[x][y] == '#') {
        return;
    }
    edgeLength++;
    if (visited[x][y] == 1) {
        if (junctions.find({x, y}) != junctions.end() && (junctionIndex[{x, y}] != prevIndex)) {
            if (forwardEdge) {
                edges.insert({prevIndex, {junctionIndex[{x, y}], edgeLength}});
            } else {
                edges.insert({junctionIndex[{x, y}], {prevIndex, edgeLength}});
            }
        }
        return;
    }
    visited[x][y] = 1;
    int count = 0;
    if (grid[x-1][y] != '#') {
        count++;
    }
    if (grid[x+1][y] != '#') {
        count++;
    }
    if (grid[x][y-1] != '#') {
        count++;
    }
    if (grid[x][y+1] != '#') {
        count++;
    }
    if (count > 2) {
//        cout << "Count > 2" << endl;
        junctions.insert({x, y});
        junctionIndex[{x, y}] = id++;
//        cout << "Junction Index: " << junctionIndex[{x, y}] << endl;
        if (forwardEdge) {
            edges.insert({prevIndex, {junctionIndex[{x, y}], edgeLength}});
//            cout << "Added edge: " << prevIndex << " " << junctionIndex[{x, y}] << " " << edgeLength << endl;
        } else {
            edges.insert({junctionIndex[{x, y}], {prevIndex, edgeLength}});
//            cout << "Added edge: " << junctionIndex[{x, y}] << " " << prevIndex << " " << edgeLength << endl;
        }
        if (grid[x-1][y] == '^') {
            dfs(x-1, y, junctionIndex[{x, y}], true, 0);
        }
        else if (grid[x-1][y] == 'v') {
            dfs(x-1, y, junctionIndex[{x, y}], false, 0);
        }
        if (grid[x+1][y] == 'v') {
            dfs(x+1, y, junctionIndex[{x, y}], true, 0);
        }
        else if (grid[x+1][y] == '^') {
            dfs(x+1, y, junctionIndex[{x, y}], false, 0);
        }
        if (grid[x][y-1] == '<') {
            dfs(x, y-1, junctionIndex[{x, y}], true, 0);
        }
        else if (grid[x][y-1] == '>') {
            dfs(x, y-1, junctionIndex[{x, y}], false, 0);
        }
        if (grid[x][y+1] == '>') {
            dfs(x, y+1, junctionIndex[{x, y}], true, 0);
        }
        else if (grid[x][y+1] == '<') {
            dfs(x, y+1, junctionIndex[{x, y}], false, 0);
        }
    }
    else if (count < 2) {
//        cout << "Count < 2" << endl;
        junctions.insert({x, y});
        junctionIndex[{x, y}] = id++;
//        cout << "Junction Index: " << junctionIndex[{x, y}] << endl;
        if (forwardEdge) {
            edges.insert({prevIndex, {junctionIndex[{x, y}], edgeLength}});
        } else {
            edges.insert({junctionIndex[{x, y}], {prevIndex, edgeLength}});
        }
        return;
    }
    else {
//        cout << "Count = 2" << endl;
        if (grid[x-1][y] != '#') {
            dfs(x - 1, y, prevIndex, forwardEdge, edgeLength);
        }
        if (grid[x+1][y] != '#') {
            dfs(x + 1, y, prevIndex, forwardEdge, edgeLength);
        }
        if (grid[x][y-1] != '#') {
            dfs(x, y - 1, prevIndex, forwardEdge, edgeLength);
        }
        if (grid[x][y+1] != '#') {
            dfs(x, y + 1, prevIndex, forwardEdge, edgeLength);
        }
    }
}

void solve() {
    string s;
    while (getline(cin, s)) {
        grid.pb(s);
    }
    int n = sz(grid);
    int m = sz(grid[0]);
    rep(i, 0, n) {
        vi temp(m, 0);
        visited.pb(temp);
    }
    grid[0][1] = '#';
    grid[n-1][m-2] = '#';
    junctionIndex[{1, 1}] = 0;
    junctions.insert({1, 1});
    visited[1][1] = 1;
    junctionIndex[{n-2, m-2}] = 1;
    junctions.insert({n-2, m-2});
    visited[n-2][m-2] = 1;
    id = 2;
    if (grid[1][2] != '#') {
        dfs(1, 2, 0, true, 0);
    }
    if (grid[2][1] != '#') {
        dfs(2, 1, 0, true, 0);
    }
    vvii adj(id);
    for (auto edge : edges) {
        adj[edge.ff].pb({edge.ss.ff, edge.ss.ss});
    }
    newVisited.resize(id, 0);
    newDFS(0, adj, 0);
    cout << longest + 2 << endl; // Add two as we are not counting the start and end points
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}