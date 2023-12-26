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
//#define endl '\n'
#define all(s) s.begin(), s.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define printcase int t; cin>>t; for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";solve();}
#define max_heap(x) priority_queue<x>
#define min_heap(x) priority_queue<x, vector<x>, greater<x>>

void solve() {
    string s;
    ll total = 0;
    vll copies;
    while(1) {
        cin >> s;
        if(s == "EOF") {
            break;
        }
        cin >> s;
        set<int> winning_numbers;
        while(1) {
            cin >> s;
            if(s == "|") {
                break;
            }
            winning_numbers.insert(stoi(s));
        }
        ll val = 0;
        rep(i, 0, 25) { // Change this value according to the number of values in the input
            cin >> s;
            if(winning_numbers.find(stoi(s)) != winning_numbers.end()) {
                val++;
            }
        }
        copies.pb(val);
    }
    vll count(sz(copies), 1);
    rep(i, 0, sz(copies)) {
        for (int j = i + 1; j < sz(copies), j < copies[i] + i + 1; j++) {
            count[j] += count[i];
        }
    }
    rep(i, 0, sz(copies)) {
        total += count[i];
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