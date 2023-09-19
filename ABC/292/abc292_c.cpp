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
// https://atcoder.jp/contests/abc292/tasks/abc292_c

int main(){
    ll n; cin >> n;
    vector<ll> cnt(n);
    rep(i, 1, n){
        for(int j = 1; j*j <= i; j++){
            if(i%j == 0){
                cnt[i]++;
                if(i/j != j) cnt[i]++;
            }
        }
    }

    ll ans = 0;
    rep(i, 1, n){
        ans += cnt[i]*cnt[n-i];
    }
    cout << ans << endl;
    
    return 0;
}