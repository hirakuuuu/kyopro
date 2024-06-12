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

/*

*/

int main(){
    ll n, p, k; cin >> n >> p >> k;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
        }
    }
    auto count = [&](ll x) -> int {
        vector<vector<ll>> dist = a;
        rep(i, 0, n){
            rep(j, 0, n){
                if(dist[i][j] == -1) dist[i][j] = x;
            }
        }
        rep(l, 0, n){
            rep(i, 0, n){
                rep(j, 0, n){
                    chmin(dist[i][j], dist[i][l]+dist[l][j]);
                }
            }
        }
        int res = 0;
        rep(i, 0, n){
            rep(j, i+1, n){
                if(dist[i][j] <= p) res++;
            }
        }
        return res;
    };

    if(count(IINF) == k){
        cout << "Infinity" << endl;
    }else if(k < count(IINF)){
        cout << 0 << endl;
    }else{
        ll ok1 = 0, ng1 = IINF;
        while(ng1-ok1 > 1){
            ll mid = (ok1+ng1)/2;
            ll tmp = count(mid);
            if(tmp <= k) ng1 = mid;
            else ok1 = mid;
        }
        // cout << ok1 << ' ' << ng1 << endl;
        ll ok2 = 0, ng2 = IINF;
        while(ng2-ok2 > 1){
            ll mid = (ok2+ng2)/2;
            ll tmp = count(mid);
            if(tmp <= k-1) ng2 = mid;
            else ok2 = mid;
        }
        // cout << ok2 << ' ' << ng2 << endl;
        cout << ok2-ok1 << endl;
        
    }


    

    return 0;
}