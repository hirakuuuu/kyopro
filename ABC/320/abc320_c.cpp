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
// https://atcoder.jp/contests/abc320/tasks/abc320_c

int main(){
    int m; cin >> m;
    vector<string> s(3);
    rep(i, 0, 3) cin >> s[i];
    int ans = IINF;
    rep(i, 0, m){
        rep(j, 0, m){
            rep(k, 0, m){
                if(s[0][i] == s[1][j] && s[1][j] == s[2][k]){
                    int tmp = max({i, j, k});
                    if(i == j && j == k && k == i) tmp = 2*m+i;
                    else if(i == j) tmp = m+i;
                    else if(i == k) tmp = m+i;
                    else if(j == k) tmp = m+j;
                    //cout << tmp << ' ' << i << ' ' << j << ' ' << k << endl;
                    chmin(ans, tmp);
    
                }
            }
        }
    }

    if(ans == IINF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}