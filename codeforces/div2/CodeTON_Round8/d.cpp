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
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<vector<ll>> a(n+1, vector<ll>(n+1));
        rep(i, 1, n+1){
            rep(j, i, n+1){
                cin >> a[i][j];
            }
        }
        vector<vector<ll>> dp(n+1, vector<ll>(k+1, -INF));
        vector<vector<ll>> acc_dp(n+1, vector<ll>(k+1, -INF));
        // k以下の間は愚直解
        dp[0][0] = acc_dp[0][0] = 0LL;
        dp[1][0] = a[1][1];
        dp[1][1] = 0;
        if(a[1][1] < 0) swap(dp[1][0], dp[1][1]);
        acc_dp[1] = dp[1]; 
        int r = 2, sum = 2;
        while(r <= n && sum < k){
            vector<ll> dp_;
            rep(i, 1<<(r-1), 1<<r){
                ll tmp = 0;
                rep(j, 0, r){
                    if(!((i>>j)&1)) continue;
                    int l = j;
                    while(l < r && (i>>l)&1) l++;
                    tmp += a[j+1][l];
                    j = l;
                }
                dp_.push_back(tmp);
            }
            sort(dp_.rbegin(), dp_.rend());
            rep(i, 0, min(k, (int)dp_.size())){
                dp[r][i] = dp_[i];
            }
            vector<ll> acc_dp_ = acc_dp[r-1];
            rep(i, 0, min(k, (int)dp_.size())){
                acc_dp_.push_back(dp_[i]);
            }
            sort(acc_dp_.rbegin(), acc_dp_.rend());
            rep(i, 0, k){
                acc_dp[r][i] = acc_dp_[i];
            }

            sum += 1<<(r-1);
            r++;
        }
        rep(i, r, n+1){
            // i] となる場合の上位ｋ個
            vector<ll> mx(i);
            rrep(j, i-2, 0){
                mx[j] = a[j+2][i];
            }
            priority_queue<pair<ll, ll>> que;
            que.push({a[1][i], -1});
            rep(j, 0, i-1){
                que.push({mx[j]+acc_dp[j][0], j});
            }
            int cnt = 0;
            vector<int> id(i-1);
            while(cnt < k){
                auto [tmp, ind] = que.top(); que.pop();
                dp[i][cnt] = tmp;
                cnt++;
                if(cnt == k) continue;
                if(ind == -1) continue;
                que.push({mx[ind]+acc_dp[ind][id[ind]+1], ind});
                id[ind]++;
            }

            vector<ll> acc_dp_ = acc_dp[i-1];
            rep(j, 0, k){
                acc_dp_.push_back(dp[i][j]);
            }
            sort(acc_dp_.rbegin(), acc_dp_.rend());
            rep(j, 0, k){
                acc_dp[i][j] = acc_dp_[j];
            }
            // rep(j, 0, k){
            //     cout << acc_dp[i][j] << ' ';
            // }
            // cout << endl;
        }
        rep(j, 0, k){
            cout << acc_dp[n][j] << ' ';
        }
        cout << endl;

    }
    
    return 0;
}