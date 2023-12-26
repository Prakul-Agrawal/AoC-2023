//
// Created by Prakul Agrawal on 12/24/23.
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
    vvi bricks(0, vi(6));
    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        vi brick(6);
        char temp;
        iss >> brick[2] >> temp >> brick[1] >> temp >> brick[0] >> temp
            >> brick[5] >> temp >> brick[4] >> temp >> brick[3];
        bricks.pb(brick);
    }
    int n = sz(bricks);
    sort(all(bricks));
    map<pii, pii> highestOccupied;
    rep(x, 0, 10)
        rep(y, 0, 10)
            highestOccupied[{x, y}] = {0, -1};
    set<int> cannotRemoveIndices;
    vvi supportGraph(n);
    rep(i, 0, n) {
        vi brick = bricks[i];
        int x1 = brick[2], y1 = brick[1], z1 = brick[0];
        int x2 = brick[5], y2 = brick[4], z2 = brick[3];
        set<int> highestIndices;
        int currHighest = 0;
        rep(x, x1, x2+1) {
            rep(y, y1, y2+1) {
                if (highestOccupied[{x, y}].ff > currHighest) {
                    currHighest = highestOccupied[{x, y}].ff;
                    highestIndices.clear();
                    highestIndices.insert(highestOccupied[{x, y}].ss);
                } else if (highestOccupied[{x, y}].ff == currHighest) {
                    highestIndices.insert(highestOccupied[{x, y}].ss);
                }
            }
        }
        rep(x, x1, x2+1)
            rep(y, y1, y2+1)
                highestOccupied[{x, y}] = {currHighest + z2 - z1 + 1, i};
        if (highestIndices.empty())
            continue;
        if (sz(highestIndices) == 1 && *highestIndices.begin() != -1) {
            cannotRemoveIndices.insert(*highestIndices.begin());
        }
        for (auto x: highestIndices) {
            if (x != -1) {
                supportGraph[x].pb(i);
            }
        }
    }
    int total = 0;
    rep(i, 0, n) {
        int count = 0;
        vi supportCount(n, 0);
        rep(j, 0, n) {
            for (auto x: supportGraph[j]) {
                supportCount[x]++;
            }
        }
        queue<int> fallingBricks;
        fallingBricks.push(i);
        while (!fallingBricks.empty()) {
            int curr = fallingBricks.front();
            fallingBricks.pop();
            count++;
            for (auto x: supportGraph[curr]) {
                supportCount[x]--;
                if (supportCount[x] == 0) {
                    fallingBricks.push(x);
                }
            }
        }
        total += count - 1;
    }
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}