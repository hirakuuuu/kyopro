#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

const double pi = 3.141592653589;
double vol(double r, double h, double ratio){
    return pi*r*r*h/3*(ratio/h)*(ratio/h)*(ratio/h);
}


int main(){
    int n, q; cin >> n >> q;
    vector<double> x(n), r(n), h(n);
    rep(i, 0, n) cin >> x[i] >> r[i] >> h[i];
    vector<double> a(q), b(q);
    rep(i, 0, q) cin >> a[i] >> b[i];
    rep(i, 0, q){
        double ans = 0;
        rep(j, 0, n){
            if(x[j] <= a[i] and b[i] <= x[j]+h[j]){
                ans += vol(r[j], h[j], h[j]-a[i]+x[j]) - vol(r[j], h[j], x[j]+h[j]-b[i]);
            }else if(x[j] <= a[i] and a[i] <= x[j]+h[j] and x[j]+h[j] <= b[i]){
                ans += vol(r[j], h[j], h[j]-a[i]+x[j]);
            }else if(a[i] <= x[j] and x[j] <= b[i] and b[i] <= x[j]+h[j]){
                ans += vol(r[j], h[j], h[j]) - vol(r[j], h[j], h[j]-b[i]+x[j]);
            }else if(a[i] <= x[j] and x[j]+h[j] <= b[i]){
                ans += vol(r[j], h[j], h[j]);
            }
        }
        printf("%.10f\n", ans);
    }
}