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

ll next_value(ll value, vector<vll> &mapping) {
    for (vll &map : mapping) {
        if (map[0] <= value && value < map[0] + map[2]) {
            return map[1] + value - map[0];
        }
    }
    return value;
}

void solve() {
    // Read seeds
    string seeds_line;
    getline(cin, seeds_line);
    istringstream seeds_stream(seeds_line);
    string word;
    seeds_stream >> word;  // Ignore the first word "Seeds:"
    vector<ll> seeds;
    ll seed;
    while (seeds_stream >> seed) {
        seeds.push_back(seed);
    }

    // Read seed-to-soil, soil-to-fertilizer, etc. mappings
    vector<vector<vll>> mappings;
    int mapping_count = -1;
    while (true) {
        string mapping_line;
        getline(cin, mapping_line);
        if (mapping_line == "EOF") {
            break;
        }
        if (mapping_line.empty()) {
            mapping_count++;
            mappings.pb(vector<vll>());
            getline(cin, mapping_line);
            continue;
        }
        istringstream mapping_stream(mapping_line);
        vll mapping;
        ll value;
        while (mapping_stream >> value) {
            mapping.pb(value);
        }
        mappings[mapping_count].pb(mapping);
    }

    ll lowest = 0, value;
    int num_of_mappings = sz(mappings);
    int num_of_seeds = sz(seeds) / 2;
    while (true) {
        value = lowest;
        for (int i = num_of_mappings - 1; i >= 0; i--) {
            value = next_value(value, mappings[i]);
        }
        rep(i, 0, num_of_seeds){
            if (seeds[2*i] <= value && value < seeds[2*i] + seeds[2*i+1]) {
                cout << lowest << endl;
                return;
            }
        }
        lowest++;
    }
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
//    tc solve();
    solve();
}