#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    ll k; cin >> k;
    vector<vector<ll>> a(n, vector<ll>(m));
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> dp1(n), dp2(n);

    rep(i, 0, (1<<(m-1))){
        vector<int> cnt(2);
        rep(j, 0, m-1){
            cnt[((i>>j)&1)]++;
        }
        if(cnt[0] > m-1 || cnt[1] > n-1) continue;
        ll tmp = a[0][0];
        int ci = 0, cj = 0;
        rep(j, 0, m-1){
            if(((i>>j)&1) == 1){
                tmp ^= a[ci+1][cj];
                ci++;
            }else{
                tmp ^= a[ci][cj+1];
                cj++;
            }
        }
        dp1[ci].push_back(tmp);
    }
    rep(i, 0, n){
        sort(dp1[i].begin(), dp1[i].end());
    }

    rep(i, 0, (1<<(n-1))){
        vector<int> cnt(2);
        rep(j, 0, n-1){
            cnt[((i>>j)&1)]++;
        }
        if(cnt[0] > m-1 || cnt[1] > n-1) continue;
        ll tmp = a[n-1][m-1];
        int ci = n-1, cj = m-1;
        rep(j, 0, n-1){
            if(((i>>j)&1) == 1){
                tmp ^= a[ci-1][cj];
                ci--;
            }else{
                tmp ^= a[ci][cj-1];
                cj--;
            }
        }
        dp2[ci].push_back(tmp^a[ci][cj]);
    }
    rep(i, 0, n){
        sort(dp2[i].begin(), dp2[i].end());
    }

    ll ans = 0;
    rep(i, 0, n){
        for(auto dd: dp1[i]){
            auto itr_l = lower_bound(dp2[i].begin(), dp2[i].end(), dd^k);
            auto itr_r = upper_bound(dp2[i].begin(), dp2[i].end(), dd^k);
            ans += (ll)(itr_r-itr_l);
        }
    }
    cout << ans << endl;
    
    return 0;
}