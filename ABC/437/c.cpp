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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> w(n), p(n);
        rep(i, 0, n){
            cin >> w[i] >> p[i];
        }
        vector<int> ind(n);
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](auto i, auto j){
            return p[i]+w[i] < p[j]+w[j];
        });

        // i: w, j: p;
        // p[j]-w[i] -> p[i]-w[j];
        // p[i]-w[j]-(p[j]-w[i]) > 0;
        // p[i]+w[i]

        int ok = 0, ng = n;
        while(ng-ok > 1){
            int mid = (ok+ng)/2;
            ll tp = 0, tw = 0;
            rep(i, 0, mid) tw += w[ind[i]];
            rep(i, mid, n) tp += p[ind[i]];
            // cout << mid << ' ' << tp << ' ' << tw << endl;;
            if(tw <= tp) ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
    }
    
    return 0;
}