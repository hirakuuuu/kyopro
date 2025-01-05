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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    ll s; cin >> s;
    vector<ll> a(n);
    ll t = 0;
    rep(i, 0, n) cin >> a[i], t += a[i];

    vector<ll> acc(n);
    rep(i, 1, n) acc[i] = acc[i-1]+a[i-1];

    ll sum_l = t-a[0];
    rep(l, 1, n+1){
        if(s >= sum_l){
            auto itr = lower_bound(acc.begin(), acc.end(), (s-sum_l)%t);
            if(itr != acc.end() && (*itr) == (s-sum_l)%t){
                cout << "Yes" << endl;
                return 0;
            }
        }
        if(l < n) sum_l -= a[l];
    }
    cout << "No" << endl;


    return 0;
}