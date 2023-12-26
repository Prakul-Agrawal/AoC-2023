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
    string time_stream;
    getline(cin, time_stream);
    istringstream time_stream_stream(time_stream);
    string ignore;
    time_stream_stream >> ignore;  // Ignore the first word "Time:"
    int time;
    vi times;
    while (time_stream_stream >> time) {
        times.pb(time);
    }
    string distance_stream;
    getline(cin, distance_stream);
    istringstream distance_stream_stream(distance_stream);
    distance_stream_stream >> ignore;  // Ignore the first word "Distance:"
    int distance;
    vi distances;
    while (distance_stream_stream >> distance) {
        distances.pb(distance);
    }

    ll count, ans = 1;
    rep(i, 0, sz(times)) {
        count = 0;
        rep(t, 0, times[i] + 1) {
            if (t * (times[i] - t) > distances[i]) {
                count++;
            }
        }
        ans *= count;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
//    tc solve();
    solve();
}