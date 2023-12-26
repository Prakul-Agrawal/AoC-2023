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
    string s;
    ll total = 0;
    while (getline(cin, s)) {
        string springs = s.substr(0, s.find(" "));
        string conditions = s.substr(s.find(" ") + 1);
        istringstream iss(conditions);
        vi condList;
        int value;
        char comma;
        while (iss >> value) {
            condList.pb(value);
            if (iss >> comma && comma != ',') {
                break;
            }
        }
        int n = sz(springs);
        int m = sz(condList);
        vector<vll> dp(n + 1, vll(m + 1, 0));

        dp[n][m] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (springs[i] == '#') {
                break;
            }
            dp[i][m] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (springs[i] == '.' || springs[i] == '?') {
                    dp[i][j] += dp[i + 1][j];
                }
                if ((springs[i] == '#' || springs[i] == '?') && (n - i == condList[j] || n - i > condList[j] && springs[i + condList[j]] != '#')) {
                    bool noDot = true;
                    rep(k, i, i + condList[j]) {
                        if (springs[k] == '.') {
                            noDot = false;
                            break;
                        }
                    }
                    if (noDot) {
                        if (n - i > condList[j])
                            dp[i][j] += dp[i + condList[j] + 1][j + 1];
                        else
                            dp[i][j] += dp[i + condList[j]][j + 1];
                    }
                }
            }
        }
        total += dp[0][0];
    }
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}