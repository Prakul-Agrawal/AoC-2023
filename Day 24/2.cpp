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

vector<vector<double>> hail;
vector<vector<double>> relativeHail;
vector<double> slopes;
double xIntersection, yIntersection;
int n;

bool areEqual(double a, double b) {
    return fabs(a - b) < 1e-9;
}

bool areEqualInts(double a, double b) {
    int p = (int) (a >= 0 ? a + 0.5 : a - 0.5);
    int q = (int) (b >= 0 ? b + 0.5 : b - 0.5);
    return p == q;
}

int getZVelocity(vector<double> hail1, vector<double> hail2, double xInter, double yInter) {
    double time1 = hail1[3] == 0 ? hail1[4] == 0 ? -999999 : (yInter - hail1[1]) / hail1[4]
                                 : (xInter - hail1[0]) / hail1[3];
    double time2 = hail2[3] == 0 ? hail2[4] == 0 ? -999999 : (yInter - hail2[1]) / hail2[4]
                                 : (xInter - hail2[0]) / hail2[3];
    if (areEqual(time1, time2) || time1 < 0 || time2 < 0) {
        return -999999;
    }
    double zVel = (hail1[2] - hail2[2] + time1 * hail1[5] - time2 * hail2[5]) / (time1 - time2);
    return (int) (zVel >= 0 ? zVel + 0.5 : zVel - 0.5);
}

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

bool forLoop(int a, int b, int c, int d){
    rep(stoneXVel, a, b) {
        rep(stoneYVel, c, d) {
            relativeHail[0][3] = hail[0][3] - stoneXVel;
            relativeHail[0][4] = hail[0][4] - stoneYVel;
            if (relativeHail[0][3] == 0) {
                slopes[0] = 999999999;
            } else {
                slopes[0] = relativeHail[0][4] / relativeHail[0][3];
            }
            double xCommon = 0, yCommon = 0;
            bool flag = false;
            rep(i, 1, n) {
                relativeHail[i][3] = hail[i][3] - stoneXVel;
                relativeHail[i][4] = hail[i][4] - stoneYVel;
                if (relativeHail[i][3] == 0) {
                    slopes[i] = 999999999;
                } else {
                    slopes[i] = relativeHail[i][4] / relativeHail[i][3];
                }
                if (intersectInFuture(relativeHail[0], slopes[0], relativeHail[i], slopes[i])) {
                    if (flag) {
                        if (!areEqualInts(xCommon, xIntersection) || !areEqualInts(yCommon, yIntersection)) {
                            flag = false;
                            break;
                        }
                    } else {
                        xCommon = xIntersection;
                        yCommon = yIntersection;
                        flag = true;
                    }
                } else {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                continue;
            }
            flag = false;
            int commonZVel = 0;
            rep(i, 1, n) {
                int stoneZVel = getZVelocity(relativeHail[0], relativeHail[i], xCommon, yCommon);
                if (stoneZVel == -999999) {
                    flag = false;
                    break;
                }
                if (flag) {
                    if (stoneZVel != commonZVel) {
                        flag = false;
                        break;
                    }
                } else {
                    commonZVel = stoneZVel;
                    flag = true;
                }
            }
            if (flag) {
                double time = relativeHail[0][3] == 0 ? (yCommon - relativeHail[0][1]) / relativeHail[0][4]
                                                      : (xCommon - relativeHail[0][0]) / relativeHail[0][3];
                double zCommon = hail[0][2] + time * (hail[0][5] - commonZVel);
//                cout << xCommon << " " << yCommon << " " << zCommon << endl;
//                cout << stoneXVel << " " << stoneYVel << " " << commonZVel << endl;
                cout << (ll) (xCommon + yCommon + zCommon) << endl;
                return true;
            }
        }
    }
    return false;
}

void solve() {
    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        vector<double> temp(6);
        char c;
        iss >> temp[0] >> c >> temp[1] >> c >> temp[2] >> c >> temp[3] >> c >> temp[4] >> c >> temp[5];
        hail.pb(temp);
    }
    n = sz(hail);
    relativeHail = hail;
    slopes.resize(n);

    int iteration = 0;
    while(true) {
        if (forLoop(-iteration, iteration, iteration, iteration + 1)) {
            break;
        }
        if (forLoop(iteration, iteration + 1, -iteration + 1, iteration + 1)) {
            break;
        }
        if (forLoop(-iteration + 1, iteration + 1, -iteration, -iteration + 1)) {
            break;
        }
        if (forLoop(-iteration, -iteration + 1, -iteration, iteration)) {
            break;
        }
        iteration++;
    }
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}