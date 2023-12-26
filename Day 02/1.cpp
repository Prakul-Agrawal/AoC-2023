//
// Created by Prakul Agrawal on 12/2/23.
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
    while(1) {
        int r = 0, g = 0, b = 0;
        getline(cin, s);
        if (s == "EOF") {
            break;
        }
        int id = 0;
        int pos = 5;
        while (s[pos] != ':'){
            id *= 10;
            id += (s[pos] - '0');
            pos++;
        }
        pos++;
        int length = sz(s);
        int curr_val = 0;
        string curr_color = "";
        bool flag = true;
        while (pos < length) {
            if (s[pos] == ';') {
                if (curr_color == "red") {
                    r += curr_val;
                } else if (curr_color == "green") {
                    g += curr_val;
                } else if (curr_color == "blue") {
                    b += curr_val;
                }
                curr_color = "";
                curr_val = 0;
                if (r > 12 || g > 13 || b > 14) {
                    flag = false;
                    break;
                }
                r = 0;
                g = 0;
                b = 0;
            } else if (s[pos] == ',') {
                if (curr_color == "red") {
                    r += curr_val;
                } else if (curr_color == "green") {
                    g += curr_val;
                } else if (curr_color == "blue") {
                    b += curr_val;
                }
                curr_color = "";
                curr_val = 0;
            } else if (s[pos] == ' ') {
                pos++;
                continue;
            } else if (s[pos] >= '0' && s[pos] <= '9') {
                curr_val *= 10;
                curr_val += (s[pos] - '0');
            } else {
                curr_color += s[pos];
            }
            pos++;
        }
        if (!flag) {
            continue;
        }
        if (curr_color == "red") {
            r += curr_val;
        } else if (curr_color == "green") {
            g += curr_val;
        } else if (curr_color == "blue") {
            b += curr_val;
        }
        if (r > 12 || g > 13 || b > 14) {
            continue;
        }
        total += id;
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