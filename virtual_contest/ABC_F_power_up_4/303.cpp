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
    ll h; cin >> h;
    vector<ll> t(n), d(n);
    rep(i, 0, n){
        cin >> t[i] >> d[i];
    }

    ll ok = h, ng = 0;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;

        __int128_t mx = 0;
        priority_queue<pair<ll, ll>> que;
        rep(i, 0, n){
            if(t[i] > mid){
                chmax(mx, d[i]);
            }else{
                que.push({t[i]*d[i], t[i]});
            }
        }

        __int128_t rest = mid;
        __int128_t hp = h;
        while(rest){
            if(que.empty()){
                hp -= mx*rest*(rest+1)/2;
                rest = 0;
            }else if(mx*rest > que.top().first){
                __int128_t num = que.top().first/mx;
                // rest-num+1
                hp -= mx*(rest+num+1)*(rest-num)/2;
                rest = num;
            }else{
                __int128_t num = que.top().second;
                assert(rest > num-1);
                hp -= que.top().first*(rest-num+1);
                rest = num-1;
            }
            while(!que.empty() && que.top().second >= rest){
                auto [td, t_] = que.top(); que.pop();
                chmax(mx, td/t_);
            }
        }
        if(hp <= 0) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    
    return 0;
}