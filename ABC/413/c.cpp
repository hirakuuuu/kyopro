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
    deque<pair<ll, ll>> a;
    int q; cin >> q;
    rep(i, 0, q){
        int t; cin >> t;
        if(t == 1){
            ll c, x; cin >> c >> x;
            a.push_back({c, x});
        }else{
            ll k; cin >> k;
            ll tot = 0;
            while(k > 0 && !a.empty()){
                auto [c, x] = a.front(); a.pop_front();
                // cout << c << ' ' << x << endl;
                if(c <= k){
                    tot += c*x;
                    k -= c;
                }else{
                    tot += k*x;
                    a.push_front({c-k, x});
                    k = 0;
                }
            }
            cout << tot << endl;
        }
        // cout << a.front().first << ' ' << a.front().second << endl;
    }
    
    return 0;
}