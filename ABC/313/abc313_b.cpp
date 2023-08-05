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
// https://atcoder.jp/contests/abc313/tasks/abc313_b

int main(){
    int n, m; cin >> n >> m;
    vector<int> cnt(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        cnt[b]++;
    }

    int f = 0, ans = -1;
    rep(i, 0, n){
        if(cnt[i] == 0){
            ans = i+1;
            f++;
        }
    }
    if(f >= 2) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}