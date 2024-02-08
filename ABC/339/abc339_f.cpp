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
// https://atcoder.jp/contests/abc339/tasks/abc339_f

int main(){
    int n; cin >> n;
    vector<ll> mod = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
    int base = 5;
    vector<vector<ll>> h(base, vector<ll>(n));
    vector<string> a(n);
    rep(i, 0, n){
        cin >> a[i];
        reverse(a[i].begin(), a[i].end());
        rep(j, 0, base){
            ll tmp = 1;
            for(auto aa: a[i]){
                ll s = (aa-'0');
                h[j][i] += s*tmp;
                h[j][i] %= mod[j];
                tmp *= 10;
                tmp %= mod[j];
            }
        }
    }

    vector<vector<ll>> sorted_h = h;
    rep(i, 0, base) sort(sorted_h[i].begin(), sorted_h[i].end());
    ll ans = 0;
    rep(i, 0, n){
        rep(j, 0, n){
            ll tmp = INF;
            rep(k, 0, base){
                ll c = (h[k][i]*h[k][j])%mod[k];
                ll cnt = upper_bound(sorted_h[k].begin(), sorted_h[k].end(), c)-lower_bound(sorted_h[k].begin(), sorted_h[k].end(), c);
                chmin(tmp, cnt);
            }
            ans += tmp;
        }
    }
    cout << ans << endl;

    
    return 0;
}