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

map<char, int> card_value;

int handType(vi &countArray) {
    if (sz(countArray) == 1)
        return 7;
    if (sz(countArray) == 2) {
        if (countArray[0] == 4)
            return 6;
        return 5;
    }
    if (sz(countArray) == 3) {
        if (countArray[0] == 3)
            return 4;
        return 3;
    }
    if (sz(countArray) == 4)
        return 2;
    return 1;
}

bool compareHands(pair<string, int> hand1, pair<string, int> hand2) {
    string cards1 = hand1.ff, cards2 = hand2.ff;
    map<char, int> mp1, mp2;
    for (char c: cards1) {
        mp1[c]++;
    }
    for (char c: cards2) {
        mp2[c]++;
    }
    vi count1, count2;
    for (auto x: mp1) {
        count1.pb(x.ss);
    }
    for (auto x: mp2) {
        count2.pb(x.ss);
    }
    sort(count1.begin(), count1.end(), greater<int>());
    sort(count2.begin(), count2.end(), greater<int>());

    int type1 = handType(count1);
    int type2 = handType(count2);

    if (type1 != type2)
        return type1 < type2;

    rep(i, 0, 5) {
        if (card_value[cards1[i]] != card_value[cards2[i]])
            return card_value[cards1[i]] < card_value[cards2[i]];
    }
    return false;
}

void solve() {
    string hand;
    int bid;
    vector<pair<string, int>> hands;
    while(true) {
        cin >> hand;
        if (hand == "EOF")
            break;
        cin >> bid;
        hands.pb({hand,bid});
    }
    card_value['A'] = 13;
    card_value['K'] = 12;
    card_value['Q'] = 11;
    card_value['J'] = 10;
    card_value['T'] = 9;
    card_value['9'] = 8;
    card_value['8'] = 7;
    card_value['7'] = 6;
    card_value['6'] = 5;
    card_value['5'] = 4;
    card_value['4'] = 3;
    card_value['3'] = 2;
    card_value['2'] = 1;

    sort(hands.begin(), hands.end(), compareHands);

    ll total = 0;
    rep(i, 0, sz(hands)) {
        total += hands[i].ss * (i + 1);
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