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
    vector<pair<char, ll>> plan;
    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        char dir;
        int steps;
        string color;
        iss >> dir >> steps >> color;
        steps = stoi(color.substr(2, 5), nullptr, 16);
        dir = color[7];
        plan.pb({dir, steps});
    }
    map<char, pii> dirMap;
    dirMap['0'] = {1, 0};
    dirMap['1'] = {0, 1};
    dirMap['2'] = {-1, 0};
    dirMap['3'] = {0, -1};
    ll x = 0, y = 0;
    ll boundary = 0;
    ll value = 0;
    for (auto p : plan) {
        char dir = p.ff;
        ll steps = p.ss;
        ll prevX = x, prevY = y;
        boundary += steps;
        x += dirMap[dir].ff * steps;
        y += dirMap[dir].ss * steps;
        value += prevX * y - prevY * x;
    }
    cout << abs(value) / 2 + boundary / 2 + 1 << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}