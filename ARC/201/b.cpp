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
        ll w; cin >> w;

        vector<vector<ll>> v(60);
        rep(i, 0, n){
            int x; cin >> x;
            ll y; cin >> y;
            v[x].push_back(y);
        }
        rep(i, 0, 60){
            sort(v[i].rbegin(), v[i].rend());
        }
        vector<vector<ll>> acc(60);
        rep(i, 0, 60){
            acc[i].resize(v[i].size()+1);
            rep(j, 0, (int)v[i].size()){
                acc[i][j+1] += acc[i][j]+v[i][j];
            }
        }
        ll ans = 0;
        rrep(i, 59, 0){
            cout << i << ' ' << w << endl;
            rep(j, 0, (int)v[i].size()){
                if(w < (1LL<<i)) break;
                bool ok = true;
                rrep(k, i-1, 0){
                    ll m = min((ll)acc[k].size()-1, (1LL<<(i-k)));
                    // cout << k << ' ' << (ll)acc[k].size()-1 << ' ' << (1LL<<(i-k)) << endl;
                    // cout << i << ' ' << v[i][j] << ' ' << k << ' ' << acc[k].back()-acc[k][(int)acc[k].size()-m] << ' ' << v[i][j] << endl;
                    if(m > 0 && acc[k][m] >= v[i][j]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    w -= 1LL<<i;
                    ans += v[i][j];
                    v[i].pop_back();
                }else{
                    break;
                }
            }
        }
        cout << w << ' ' << ans << endl;

    }
    return 0;
}