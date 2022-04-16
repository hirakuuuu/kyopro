#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc248/tasks/abc248_e

int main(){
    ll n, k; cin >> n >> k;
    vector<int> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    if(k == 1){
        cout << "Infinity" << endl;
        return 0;
    }
    map<vector<int>, int> vec;
    ll ans = 0;
    rep(i, 0, n){
        rep(j, i+1, n){
            vector<int> v = {x[j]-x[i], y[i]-y[j], -(x[j]-x[i])*y[i]+(y[j]-y[i])*x[i]};
            int cnt = 0;
            vector<int> p;
            rep(l, 0, n){
                if(v[0]*y[l]+v[1]*x[l]+v[2] == 0){
                    cnt++;
                    p.push_back(l);
                }
            }
            if(!vec[p] and cnt >= k){
                ans++;
                vec[p] = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}