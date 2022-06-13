#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc255/tasks/abc255_b

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(k);
    rep(i, 0, k){
        cin >> a[i];
        a[i]--;
    }

    vector<double> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    double max_d = 0;

    rep(i, 0, n){
        double dist = pow(10, 9)+7;
        rep(j, 0, k){
            dist = min(dist, sqrt((x[i]-x[a[j]])*(x[i]-x[a[j]])+(y[i]-y[a[j]])*(y[i]-y[a[j]])));
        }
        max_d = max(max_d, dist);
    }
    printf("%.10f\n", max_d);
    

    return 0;
}