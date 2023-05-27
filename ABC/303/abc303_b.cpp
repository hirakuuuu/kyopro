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
// https://atcoder.jp/contests/abc303/tasks/abc303_b

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    rep(i, 0, m){
        rep(j, 0, n) cin >> a[i][j];
    }

    int ans = 0;
    rep(i, 1, n+1){
        rep(j, i+1, n+1){
            bool f = false;
            rep(k, 0, m){
                rep(l, 0, n-1){
                    if((a[k][l] == i && a[k][l+1] == j) || (a[k][l] == j && a[k][l+1] == i)) f = true;
                }
            }
            if(!f) ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}