//
// Created by Prakul Agrawal on 12/18/23.
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
    string directions;
    getline(cin, directions);
    string s;
    getline(cin, s);
    map<string, pair<string, string>> mp;
    while (getline(cin, s)) {
        if (s == "EOF") {
            break;
        }
        string key = s.substr(0, 3);
        string valLeft = s.substr(7, 3);
        string valRight = s.substr(12, 3);
        mp[key] = {valLeft, valRight};
    }
    string pos = "AAA";
    ll count = 0;
    ll length = sz(directions);
    while(pos != "ZZZ"){
        count++;
        string left = mp[pos].ff;
        string right = mp[pos].ss;
        if(directions[(count-1)%length] == 'L'){
            pos = left;
        } else {
            pos = right;
        }
    }
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
//    tc solve();
    solve();
}