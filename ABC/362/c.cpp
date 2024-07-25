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

int main(){
    int n; cin >> n;
    vector<ll> l(n), r(n);
    rep(i, 0, n) cin >> l[i] >> r[i];

    ll sum = 0;
    rep(i, 0, n) sum += r[i];
    vector<ll> x = r;
    rep(i, 0, n){
        if(sum > 0){
            if(r[i]-l[i] > sum){
                x[i] -= sum;
                sum = 0;
            }else{
                x[i] -= r[i]-l[i];
                sum -= r[i]-l[i];
            }
        }
    }
    if(sum == 0){
        cout << "Yes" << endl;
        rep(i, 0, n) cout << x[i] << ' ';
        cout << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}