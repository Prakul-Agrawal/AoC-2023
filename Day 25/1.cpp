//
// Created by Prakul Agrawal on 12/26/23.
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

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); } // if you need flows
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L,0,31) do { // 'int L=30' maybe faster for random data
                lvl = ptr = vi(sz(q));
                int qi = 0, qe = lvl[s] = 1;
                while (qi < qe && !lvl[t]) {
                    int v = q[qi++];
                    for (Edge e : adj[v])
                        if (!lvl[e.to] && e.c >> (30 - L))
                            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
                }
                while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
            } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

void solve() {
    map<string, int> nodeMap;
    vvi adj;
    string s;
    int index = 0;
    while(getline(cin, s)) {
        istringstream iss(s);
        string key;
        iss >> key;
        key = key.substr(0, key.length() - 1);
        if(nodeMap.find(key) == nodeMap.end()) {
            nodeMap[key] = index++;
            adj.pb(vi());
        }
        string connection;
        while(iss >> connection) {
            if (nodeMap.find(connection) == nodeMap.end()) {
                nodeMap[connection] = index++;
                adj.pb(vi());
            }
            adj[nodeMap[key]].pb(nodeMap[connection]);
            adj[nodeMap[connection]].pb(nodeMap[key]);
        }
    }
    int n = sz(adj);
    bool found = false;
    rep(i, 0, n - 1) {
        rep(j, i + 1, n) {
            Dinic flow(n);
            rep(a, 0, n) {
                for(auto b : adj[a]) {
                    flow.addEdge(a, b, 1);
                }
            }
            ll val = flow.calc(i, j);
            if(val == 3) {
                int count = 0;
                rep(k, 0, n)
                    count += flow.leftOfMinCut(k);
                cout << count * (n - count) << endl;
                found = true;
                break;
            }
        }
        if(found)
            break;
    }
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}