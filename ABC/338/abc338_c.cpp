#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
// https://atcoder.jp/contests/abc338/tasks/abc338_c

int main(){
    int n; cin >> n;
    vector<ll> q(n), a(n), b(n);
    rep(i, 0, n) cin >> q[i];
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    int ans = 0;
    rep(i, 0, 1000001){
        vector<ll> q_ = q;
        bool f = true;
        rep(j, 0, n){
            if(q_[j] < a[j]*i) f = false;
            q_[j] -= a[j]*i;
        }
        if(f){
            ll mi = IINF;
            rep(j, 0, n){
                if(b[j] == 0) continue;
                chmin(mi, q_[j]/b[j]);
            }
            chmax(ans, i+mi);
        }
    }
    cout << ans << endl;


    
    return 0;
}