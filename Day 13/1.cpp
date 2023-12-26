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

bool isPalindrome(string s) {
    int n = sz(s);
    for(int i = 0; i < n/2; i++) {
        if(s[i] != s[n-i-1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    string s;
    ll total = 0;
    while(getline(cin, s)) {
        vector<string> pattern;
        pattern.pb(s);
        while(getline(cin, s) && !s.empty()) {
            pattern.pb(s);
        }
        int n = sz(pattern);
        int m = sz(pattern[0]);
        map<int, int> vert, hor;
        rep(i, 0, n) {
            string testString = "";
            for (int j = 2; j <= m; j += 2) {
                testString += pattern[i][j-2];
                testString += pattern[i][j-1];
                if (isPalindrome(testString)) {
                    vert[j/2]++;
                }
            }
            string reversePattern = pattern[i];
            reverse(all(reversePattern));
            testString = "";
            for (int j = 2; j < m; j += 2) {
                testString += reversePattern[j-2];
                testString += reversePattern[j-1];
                if (isPalindrome(testString)) {
                    vert[m - j/2]++;
                }
            }
        }
        rep(i, 0, m) {
            string testString = "";
            for (int j = 2; j <= n; j += 2) {
                testString += pattern[j-2][i];
                testString += pattern[j-1][i];
                if (isPalindrome(testString)) {
                    hor[j/2]++;
                }
            }
            string reversePattern = "";
            for(int j = n-1; j >= 0; j--) {
                reversePattern += pattern[j][i];
            }
            testString = "";
            for (int j = 2; j < n; j += 2) {
                testString += reversePattern[j-2];
                testString += reversePattern[j-1];
                if (isPalindrome(testString)) {
                    hor[n - j/2]++;
                }
            }
        }
        for(auto pos: vert) {
            if (pos.ss == n)
                total += pos.ff;
        }
        for(auto pos: hor) {
            if (pos.ss == m)
                total += 100 * pos.ff;
        }
    }
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}