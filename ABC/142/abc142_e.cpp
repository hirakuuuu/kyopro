#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll mod = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    vector<int> key(m);
    rep(i, 0, m){
        cin >> a[i] >> b[i];
        rep(j, 0, b[i]){
            int c; cin >> c;
            c--;
            key[i] += (1<<c);
        }
    }
    vector<int> dp(1<<n, IINF);
    dp[0] = 0;
    rep(i, 0, m){
        rep(j, 0, 1<<n){
            chmin(dp[j|key[i]], dp[j]+a[i]);
        }
    }
    if(dp[(1<<n)-1] == IINF) cout << -1 << endl;
    else cout << dp[(1<<n)-1] << endl;


    return 0;
}