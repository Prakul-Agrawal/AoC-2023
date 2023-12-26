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

void solve() {
    vector<string> grid;
    string s;
    while(getline(cin, s)) {
        grid.pb(s);
    }
    int n = sz(grid);
    int m = sz(grid[0]);

    vll vertLoc(n, 1), horLoc(m, 1);

    rep(i, 0, n){
        bool noUniverse = true;
        rep(j, 0, m){
            if(grid[i][j] == '#'){
                noUniverse = false;
                break;
            }
        }
        if(noUniverse){
            vertLoc[i] = 1000000;
        }
    }
    rep(i, 0, m){
        bool noUniverse = true;
        rep(j, 0, n){
            if(grid[j][i] == '#'){
                noUniverse = false;
                break;
            }
        }
        if(noUniverse){
            horLoc[i] = 1000000;
        }
    }
    rep(i, 1, n)
        vertLoc[i] += vertLoc[i-1];
    rep(i, 1, m)
        horLoc[i] += horLoc[i-1];

    vector<pair<ll, ll>> galaxies;
    rep(i, 0, n){
        rep(j, 0, m){
            if(grid[i][j] == '#'){
                galaxies.pb({vertLoc[i], horLoc[j]});
            }
        }
    }
    ll ans = 0;
    rep(i, 0, sz(galaxies)){
        rep(j, i+1, sz(galaxies)){
            ans += abs(galaxies[i].ff - galaxies[j].ff) + abs(galaxies[i].ss - galaxies[j].ss);
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