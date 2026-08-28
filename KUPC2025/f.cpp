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
    ll a, b; cin >> a >> b;
    vector<ll> y;
    for(ll i = 1; i*i <= b; i++){
        if(b%i == 0){
            y.push_back(i);
            if(i != b/i) y.push_back(b/i);
        }
    }
    sort(y.begin(), y.end());


    int q; cin >> q;
    __int128_t A = a, B = b;
    unordered_map<ll, ll> memo;
    while(q--){
        ll x; cin >> x;
        if(memo.count(x)){
            cout << memo[x] << endl;
            continue;
        }
        set<ll> ss;
        ss.insert(x);
        queue<ll> que;
        que.push(x);
        while(!que.empty()){
            ll qx = que.front(); que.pop();
            for(auto yy: y){
                if(qx%yy != 0) continue;
                __int128_t G = yy;
                if(G*(A*G+B)%qx == 0){
                    ll z = G*(A*G+B)/qx;
                    if(z > 1e16) continue;
                    if(gcd(qx, z) == yy && !ss.count(z)){
                        ss.insert(z);
                        que.push(z);
                    }
                }
            }
        }
        ll ans = 0;
        for(auto sss: ss) ans ^= sss;
        for(auto sss: ss) memo[sss] = ans;
        cout << ans << endl;
    }

    return 0;
}