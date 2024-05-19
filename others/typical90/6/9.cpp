#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const long double pi = 3.14159265358979;

/*
偏角がどの範囲かが全然わかってない
ライブラリを作る
*/

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    long double mx = 0.0;
    rep(i, 0, n){
        vector<long double> angle(n);
        rep(j, 0, n){
            if(i == j) angle[j] = 0.0;
            else if(y[i] == y[j]){
                if(x[j] < x[i]) angle[j] = pi;
            }else if(x[i] == x[j]){
                if(y[j] > y[i]) angle[j] = pi/2.0;
                else angle[j] = pi*3.0/2.0;
            }else{
                angle[j] = atan((long double)(y[j]-y[i])/(long double)(x[j]-x[i]));
                if(angle[j] < 0) angle[j] = pi+angle[j];
                if(y[j] < y[i]) angle[j] += pi;
            }
        }
        sort(angle.begin(), angle.end());
        set<long double> s;
        rep(j, 1, n){
            if(angle[j] < pi){
                if(!s.empty()) chmax(mx, angle[j]-*s.begin());
            }else{
                if(!s.empty()){
                    auto itr = s.lower_bound(angle[j]-pi);
                    if(itr == s.begin()) chmax(mx, angle[j]-*s.begin());
                    else{
                        auto itr_ = itr;
                        itr_--;
                        if(itr == s.end()) chmax(mx, 2.0*pi-(angle[j]-*itr_));
                        else chmax(mx, max(angle[j]-*itr, 2.0*pi-(angle[j]-*itr_)));
                    }
                }
            }
            s.insert(angle[j]);
            // cout << i << ' ' << setprecision(20) << angle[j] << ' ' << setprecision(20) << mx << endl;

        }
    }
    long double ans = 180.0*mx/pi;
    cout << setprecision(20) << ans << endl;


    return 0;
}