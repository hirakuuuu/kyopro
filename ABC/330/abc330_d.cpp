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
// https://atcoder.jp/contests/abc330/tasks/abc330_d

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    vector<ll> sh(n), sw(n);
    rep(i, 0, n){
        rep(j, 0, n){
            if(s[i][j] == 'o'){
                sh[i]++;
                sw[j]++;
            }
        }
    }

    ll ans = 0;
    rep(i, 0, n){
        rep(j, 0, n){
            if(s[i][j] == 'o'){
                ans += (sh[i]-1)*(sw[j]-1);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}