//
// Created by Prakul Agrawal on 12/23/23.
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

map<string, int> moduleType;
map<string, vector<string>> flipFlops;
map<string, pair<vector<string>, vector<string>>> conjunctions;
vector<string> broadcaster;
map<string, bool> flipFlopsState;
map<string, map<string, bool>> conjunctionsState;

void solve() {
    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        string name;
        iss >> name;
        string temp;
        iss >> temp;
        vector<string> inputs;
        while (iss >> temp) {
            if (temp[sz(temp) - 1] == ',') {
                temp = temp.substr(0, sz(temp) - 1);
            }
            inputs.push_back(temp);
        }
        if (name == "broadcaster") {
            broadcaster = inputs;
        }
        else if (name[0] == '%') {
            moduleType[name.substr(1)] = 0;
            flipFlops[name.substr(1)] = inputs;
            flipFlopsState[name.substr(1)] = false;
        }
        else {
            moduleType[name.substr(1)] = 1;
            conjunctions[name.substr(1)] = {inputs, {}};
        }
    }
    for (auto str: broadcaster) {
        if (moduleType[str]) {
            conjunctions[str].ss.pb("broadcaster");
            conjunctionsState[str]["broadcaster"] = false;
        }
    }
    for (auto str: flipFlops) {
        for (auto module: str.ss) {
            if (moduleType[module]) {
                conjunctions[module].ss.pb(str.ff);
                conjunctionsState[module][str.ff] = false;
            }
        }
    }
    for (auto str: conjunctions) {
        for (auto module: str.ss.ff) {
            if (moduleType[module]) {
                conjunctions[module].ss.pb(str.ff);
                conjunctionsState[module][str.ff] = false;
            }
        }
    }
    string rxSender = "";
    for (auto conj: conjunctions) {
        for (auto str: conj.ss.ff) {
            if (str == "rx") {
                rxSender = conj.ff;
                break;
            }
        }
        if (rxSender != "")
            break;
    }
    vector<string> endModules;
    for (auto conj: conjunctions) {
        for (auto str: conj.ss.ff) {
            if (str == rxSender) {
                endModules.pb(conj.ff);
            }
        }
    }
    for (auto flfl : flipFlops) {
        for (auto str: flfl.ss) {
            if (str == rxSender) {
                endModules.pb(flfl.ff);
            }
        }
    }
    vll cycleLengths;
    map<string, bool> flipFlopsStateCopy = flipFlopsState;
    map<string, map<string, bool>> conjunctionsStateCopy = conjunctionsState;
    for (auto endStr: endModules) {
        ll count = 0;
        bool done = false;
        while (!done) {
            count++;
            done = false;
            queue<pair<bool, pair<string, string>>> signalQueue;
            for (auto str: broadcaster) {
                signalQueue.push({false, {"broadcaster", str}});
            }
            while(!signalQueue.empty()) {
                auto signal = signalQueue.front();
                bool value = signal.ff;
                string sender = signal.ss.ff;
                string receiver = signal.ss.ss;
                if (receiver == endStr && !value) {
                    cycleLengths.pb(count);
                    done = true;
                    break;
                }
                signalQueue.pop();
                if (moduleType[receiver]) {
                    conjunctionsState[receiver][sender] = value;
                    bool sendingFlag = false;
                    for (auto module: conjunctions[receiver].ss) {
                        if (!conjunctionsState[receiver][module]) {
                            sendingFlag = true;
                            break;
                        }
                    }
                    for (auto module: conjunctions[receiver].ff) {
                        signalQueue.push({sendingFlag, {receiver, module}});
                    }
                } else if (!value) {
                    flipFlopsState[receiver] = !flipFlopsState[receiver];
                    for (auto module: flipFlops[receiver]) {
                        signalQueue.push({flipFlopsState[receiver], {receiver, module}});
                    }
                }
            }
        }
        flipFlopsState = flipFlopsStateCopy;
        conjunctionsState = conjunctionsStateCopy;
    }
    ll product = 1;
    for (auto len: cycleLengths) {
        product *= len; // LCM because they are all prime
    }
    cout << product << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}