#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc275/tasks/abc275_c

double dist(pii p1, pii p2){
    return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
}

bool check(pii p){
    return (0 <= p.first and p.first < 9 and 0 <= p.second and p.second < 9);
}

int main(){
    vector<string> s(9);
    rep(i, 0, 9) cin >> s[i];
    ll ans = 0;

    vector<pii> porn;
    rep(i, 0, 9){
        rep(j, 0, 9){
            if(s[i][j] == '#'){
                porn.push_back({i, j});
            }
        }
    }
    int n = porn.size();


    rep(i, 0, n){
        rep(j, i+1, n){
            pair<double, double> p1 = porn[i], p2 = porn[j];
            double x1 = (double)(p1.first+p2.first)/2+(-p1.second+p2.second)/2;
            double y1 = (double)(p1.second+p2.second)/2+(p1.first-p2.first)/2;
            if(x1 != ceil(x1) or y1 != ceil(y1)){
                continue;
            }
            pii p3 = {(int)ceil(x1), (int)ceil(y1)};

            double x2 = (double)(p1.first+p2.first)/2-(-p1.second+p2.second)/2;
            double y2 = (double)(p1.second+p2.second)/2-(p1.first-p2.first)/2;
            //cout << x2 << " " << y2 << endl;
            if(x2 != ceil(x2) or y2 != ceil(y2)){
                continue;
            }
            pii p4 = {(int)ceil(x2), (int)ceil(y2)};

            if(check(p3) and check(p4) and s[p3.first][p3.second] == '#' and s[p4.first][p4.second] == '#'){
                ans++;
            }
        }
    }

    
    cout << ans/2 << endl;
    return 0;
}