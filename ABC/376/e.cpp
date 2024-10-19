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
        int n, k; cin >> n >> k;
        vector<pair<ll, ll>> ab(n);
        rep(i, 0, n) cin >> ab[i].first;
        rep(i, 0, n) cin >> ab[i].second;
        sort(ab.begin(), ab.end());

        ll ans = INF;
        if(k == 1){
            rep(i, 0, n){
                chmin(ans, ab[i].first*ab[i].second);
            }
        }else{
            multiset<ll> mi;
            ll mi_sum = 0;
            rep(i, 0, k-1){
                mi.insert(ab[i].second);
                mi_sum += ab[i].second;
            }
            chmin(ans, ab[k-1].first*(mi_sum+ab[k-1].second));
            rep(i, k, n){
                // mi_sum を更新する
                ll mi_mx = *(mi.rbegin());
                if(ab[i-1].second < mi_mx){
                    mi_sum -= mi_mx;
                    mi.erase(mi.find(mi_mx));
                    mi.insert(ab[i-1].second);
                    mi_sum += ab[i-1].second;
                }
                chmin(ans, ab[i].first*(mi_sum+ab[i].second));
            }
        }
        cout << ans << endl;

    }
    
    return 0;
}