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

    pii startPos;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(grid[i][j] == 'S') {
                startPos = {i, j};
            }
        }
    }
    char startChar, lastDir;
    bool north = false, south = false, east = false, west = false;
    if (startPos.ff > 0 && (grid[startPos.ff - 1][startPos.ss] == '|' || grid[startPos.ff - 1][startPos.ss] == 'F' || grid[startPos.ff - 1][startPos.ss] == '7')) {
        north = true;
    }
    if (startPos.ff < n - 1 && (grid[startPos.ff + 1][startPos.ss] == '|' || grid[startPos.ff + 1][startPos.ss] == 'L' || grid[startPos.ff + 1][startPos.ss] == 'J')) {
        south = true;
    }
    if (startPos.ss > 0 && (grid[startPos.ff][startPos.ss - 1] == '-' || grid[startPos.ff][startPos.ss - 1] == 'F' || grid[startPos.ff][startPos.ss - 1] == 'L')) {
        west = true;
    }
    if (startPos.ss < m - 1 && (grid[startPos.ff][startPos.ss + 1] == '-' || grid[startPos.ff][startPos.ss + 1] == '7' || grid[startPos.ff][startPos.ss + 1] == 'J')) {
        east = true;
    }
    if (north && south) {
        startChar = '|';
        lastDir = 'S';
    } else if (east && west) {
        startChar = '-';
        lastDir = 'W';
    } else if (north && east) {
        startChar = 'L';
        lastDir = 'E';
    } else if (north && west) {
        startChar = 'J';
        lastDir = 'W';
    } else if (south && east) {
        startChar = 'F';
        lastDir = 'S';
    } else if (south && west) {
        startChar = '7';
        lastDir = 'W';
    }
    grid[startPos.ff][startPos.ss] = startChar;
    pii currPos = startPos;
    char currChar = startChar;
    set <pii> boundary;
    while(true) {
        boundary.insert(currPos);
        if (currChar == '|') {
            if (lastDir == 'S') {
                currPos.ff--;
            } else {
                currPos.ff++;
            }
        } else if (currChar == '-') {
            if (lastDir == 'E') {
                currPos.ss--;
            } else {
                currPos.ss++;
            }
        } else if (currChar == 'L') {
            if (lastDir == 'E') {
                currPos.ff--;
                lastDir = 'S';
            } else {
                currPos.ss++;
                lastDir = 'W';
            }
        } else if (currChar == 'J') {
            if (lastDir == 'W') {
                currPos.ff--;
                lastDir = 'S';
            } else {
                currPos.ss--;
                lastDir = 'E';
            }
        } else if (currChar == 'F') {
            if (lastDir == 'S') {
                currPos.ss++;
                lastDir = 'W';
            } else {
                currPos.ff++;
                lastDir = 'N';
            }
        } else if (currChar == '7') {
            if (lastDir == 'W') {
                currPos.ff++;
                lastDir = 'N';
            } else {
                currPos.ss--;
                lastDir = 'E';
            }
        }
        if (currPos.ff == startPos.ff && currPos.ss == startPos.ss) {
            break;
        }
        currChar = grid[currPos.ff][currPos.ss];
    }
    ll count = 0;
    rep(i, 0, n) {
        bool inside = false;
        char lastCorner;
        rep(j, 0, m) {
            bool isBoundary = (boundary.find({i, j}) != boundary.end());
            if (!isBoundary && inside) {
                count++;
            }
            else if (grid[i][j] == '|' && isBoundary) {
                inside = !inside;
            }
            else if ((grid[i][j] == 'L' || grid[i][j] == 'F') && isBoundary) {
                lastCorner = grid[i][j];
            }
            else if (grid[i][j] == 'J' && lastCorner == 'F' && isBoundary) {
                inside = !inside;
            }
            else if (grid[i][j] == '7' && lastCorner == 'L' && isBoundary) {
                inside = !inside;
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