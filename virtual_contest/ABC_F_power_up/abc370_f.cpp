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
// using mint2 = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<ll> acc(2*n+1);
    rep(i, 0, 2*n) acc[i+1] += acc[i]+a[i%n];

    ll ok = 0, ng = acc[n]/k+1;
    int ans = 0;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        // mid で切り分ける
        vector<vector<pair<int, int>>> dp(20, vector<pair<int, int>>(n));
        rep(i, 0, n){
            int pos = lower_bound(acc.begin()+i, acc.end(), acc[i]+mid)-acc.begin();
            assert(pos < i+n);
            dp[0][i] = {0, pos%n};
            if(dp[0][i].second == i) dp[0][i].first = 1;
        }
        rep(j, 1, 20){
            rep(l, 0, n){
                auto [cnt1, nxt1] = dp[j-1][l];
                auto [cnt2, nxt2] = dp[j-1][nxt1];
                int ncnt = cnt1+cnt2, nnxt = nxt2;
                if(l <= nxt1){
                    if(inr(l, nxt2, nxt1)) ncnt++;
                }else{
                    if(!inr(nxt1, nxt2, l)) ncnt++;
                }
                dp[j][l] = {ncnt, nnxt};
            }
        }

        int cnt = 0;
        rep(i, 0, n){
            pair<int, int> tmp = {0, i};
            rep(j, 0, 20){
                if((k>>j)&1){
                    tmp.first += dp[j][tmp.second].first;
                    if(i <= tmp.second){
                        if(inr(i, dp[j][tmp.second].second, tmp.second)) tmp.first++;
                    }else{
                        if(!inr(tmp.second, dp[j][tmp.second].second, i)) tmp.first++;
                    }
                    tmp.second = dp[j][tmp.second].second;
                }
            }
            cnt += ((tmp.first == 0) || (tmp.first == 1 && tmp.second == i));
        }


        if(cnt) ok = mid, ans = cnt;
        else ng = mid;
    }
    cout << ok << ' ' << n-ans << endl;


    
    return 0;
}