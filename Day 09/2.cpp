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

ll nextValue(vll &seq, int length) {
    vll newSeq;
    bool flag = true;
    ll value;
    rep(i, 0, length - 1) {
        value = seq[i + 1] - seq[i];
        newSeq.pb(value);
        if (value != 0) {
            flag = false;
        }
    }
    if (flag) {
        return 0;
    } else {
        return nextValue(newSeq, length - 1) + *newSeq.rbegin();
    }
}

void solve() {
    string seq;
    vector<vll> sequences;
    while(getline(cin, seq)) {
        istringstream seqStream(seq);
        ll val;
        vll nums;
        while(seqStream >> val) {
            nums.pb(val);
        }
        sequences.pb(nums);
    }
    ll total = 0;
    for (auto &sequence : sequences) {
        reverse(all(sequence));
        total += nextValue(sequence, sz(sequence)) + *sequence.rbegin();
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