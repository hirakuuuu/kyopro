#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc187/tasks/abc187_f


int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    map<pair<int, int>, bool> edge;
    rep(i, 0, m){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        edge[{a[i], b[i]}] = edge[{b[i], a[i]}] = true;
    }

    vector<bool> p(1<<n);
    p[0] = true;
    rep(i, 0, (1<<n)){
        if(!p[i]) continue;
        rep(j, 0, n){
            if(!((i>>j)&1)){
                bool f = true;
                rep(k, 0, n){
                    if((i>>k)&1){
                        f &= edge[{j, k}];
                    }
                }
                if(f) p[i+(1<<j)] = true;
            }
        }
    }

    vector<int> dp(1<<n, IINF);
    dp[0] = 0;
    rep(i, 1, 1<<n){
        if(p[i]) dp[i] = 1;
    }
    rep(i, 1, 1<<n){
        for(int j = i; j != 0; j = (j-1)&i){
            chmin(dp[i], dp[j]+dp[i-j]);
        }
    }
    cout << dp[(1<<n)-1] << endl;
    
    return 0;
}