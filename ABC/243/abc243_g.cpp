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
// https://atcoder.jp/contests/abc243/tasks/abc243_g

int mx = 54775;

int main(){
    int t; cin >> t;
    auto sqrt = [](ll x)->ll{ // sqrtの誤差がないバージョン
        ll l = 0, r = (ll)3e9+100;
        while(r-l > 1){
            ll mid = (l+r)/2;
            if(mid*mid <= x) l = mid;
            else r = mid;
        }
        return l;
    };
    vector<ll> square(mx);
    rep(i, 1, mx){
        ll tmp = i;
        square[i] = tmp*tmp;
    }
    vector<ll> num(mx, -1);
    auto dfs = [&](auto self, ll tmp) -> ll {
        if(tmp == 1) return num[tmp] = 1;
        if(num[tmp] != -1) return num[tmp];
        ll res = 0, r = sqrt(tmp);
        rep(l, 1, r+1){
            res += self(self, l);
        }
        return num[tmp] = res;
    };
    rep(i, 1, mx) dfs(dfs, i);


    while(t--){
        ll x; cin >> x;
        ll sx = sqrt(x);

        ll ans = 0, acc = 0;
        rep(i, 1, mx){
            if(x < i*i*i*i) break;
            ll range = min(sx+1, square[i+1])-square[i];
            acc += num[i];
            // cout << range << ' ' << acc << endl;
            ans += range*acc;
        }
        cout << ans << endl;
    }
    
    return 0;
}