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

double xIntersection, yIntersection;

bool intersectInFuture(vector<double> hail1, double slope1, vector<double> hail2, double slope2) {
    if (slope1 == slope2) {
        return false;
    }
    if (slope1 == 999999999) {
        xIntersection = hail1[0];
        yIntersection = slope2 * (xIntersection - hail2[0]) + hail2[1];
    }
    else if (slope2 == 999999999) {
        xIntersection = hail2[0];
        yIntersection = slope1 * (xIntersection - hail1[0]) + hail1[1];
    }
    else {
        xIntersection = (hail2[1] - hail1[1] + slope1 * hail1[0] - slope2 * hail2[0]) / (slope1 - slope2);
        yIntersection = slope1 * (xIntersection - hail1[0]) + hail1[1];
    }
    if ((xIntersection - hail1[0]) < 0 && hail1[3] > 0 || (xIntersection - hail1[0]) > 0 && hail1[3] < 0) {
        return false;
    }
    if ((xIntersection - hail2[0]) < 0 && hail2[3] > 0 || (xIntersection - hail2[0]) > 0 && hail2[3] < 0) {
        return false;
    }
    return true;
}

void solve() {
    vector<vector<double>> hail;
    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        vector<double> temp(6);
        char c;
        iss >> temp[0] >> c >> temp[1] >> c >> temp[2] >> c >> temp[3] >> c >> temp[4] >> c >> temp[5];
        hail.pb(temp);
    }
    int n = sz(hail);
    vector<double> slopes(n);
    for (int i = 0; i < n; i++) {
        if (hail[i][3] == 0) {
            slopes[i] = 999999999;
        }
        else {
            slopes[i] = hail[i][4] / hail[i][3];
        }
    }
    int count = 0;
    double lowerBound = 200000000000000, upperBound = 400000000000000;
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            if (intersectInFuture(hail[i], slopes[i], hail[j], slopes[j])) {
                if (xIntersection >= lowerBound && xIntersection <= upperBound &&
                    yIntersection >= lowerBound && yIntersection <= upperBound) {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}