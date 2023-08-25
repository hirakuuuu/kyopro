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
// https://atcoder.jp/contests/abc306/tasks/abc306_e

int main(){
    ll n, k, q; cin >> n >> k >> q;
    vector<ll> a(n);

    if(n == k){
        ll ans = 0;
        while(q--){
            ll x, y; cin >> x >> y;
            x--;
            ans -= a[x];
            a[x] = y;
            ans += a[x];
            cout << ans << '\n';
        }
    }else{
        multiset<ll> max_s;
        multiset<ll> min_s;
        rep(i, 0, k) max_s.insert(0LL);
        rep(i, k, n) min_s.insert(0LL);

        ll ans = 0;
        while(q--){
            ll x, y; cin >> x >> y;
            x--;
            if(a[x] <= *(min_s.rbegin())){
                min_s.erase(min_s.find(a[x]));
                a[x] = y;

                ll y_ = *(max_s.begin());
                if(y <= y_){
                    min_s.insert(y);
                }else{
                    max_s.erase(max_s.find(y_));
                    ans -= y_;
                    max_s.insert(y);
                    ans += y;
                    min_s.insert(y_);
                }

            }else{
                max_s.erase(max_s.find(a[x]));
                ans -= a[x];
                a[x] = y;

                ll y_ = *min_s.rbegin();
                if(y >= y_){
                    max_s.insert(y);
                    ans += y;
                }else{
                    min_s.erase(min_s.find(y_));
                    min_s.insert(y);
                    max_s.insert(y_);
                    ans += y_;
                }
            }
            cout << ans << '\n';
        }
    }


    return 0;
}