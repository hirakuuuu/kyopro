#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> acc(n+1);
    rep(i, 0, n){
        cin >> a[i];
        acc[i+1] += acc[i]+a[i];
    }

    ll ans = INF;

    auto calc = [&](pair<ll, ll> s, pair<ll, ll> t) -> ll {
        return max({s.first, s.second, t.first, t.second})-min({s.first, s.second, t.first, t.second});
    };
    rep(i, 2, n-1){
        // [0, i), [i, n) を半分に分ける
        pair<ll, ll> s1 = {-INF, INF}, s2 = {-INF, INF};
        {
            int l = 0, r = i;
            ll tmp = acc[r]-acc[l];
            int m = lower_bound(acc.begin()+l+1, acc.begin()+r, tmp/2+acc[l])-acc.begin();
            // cout << tmp << ' ' << m <<  endl;
            if(m != r) s1 = {acc[m]-acc[l], acc[r]-acc[m]};
            if(m != l+1) s2 = {acc[m-1]-acc[l], acc[r]-acc[m-1]};
        }
        pair<ll, ll> t1 = {-INF, INF}, t2 = {-INF, INF};
        {
            int l = i, r = n;
            ll tmp = acc[r]-acc[l];
            int m = lower_bound(acc.begin()+l+1, acc.begin()+r, tmp/2+acc[l])-acc.begin();
            // cout << tmp << ' ' << m <<  endl;
            if(m != r) t1 = {acc[m]-acc[l], acc[r]-acc[m]};
            if(m != l+1) t2 = {acc[m-1]-acc[l], acc[r]-acc[m-1]};
        }

        // cout << i << endl;
        // cout << s1.first << ' ' << s1.second << ' ' << s2.first << ' ' << s2.second << endl;
        // cout << t1.first << ' ' << t1.second << ' ' << t2.first << ' ' << t2.second << endl;
        chmin(ans, calc(s1, t1));
        chmin(ans, calc(s1, t2));
        chmin(ans, calc(s2, t1));
        chmin(ans, calc(s2, t2));
    }
    cout << ans << endl;

    return 0;
}