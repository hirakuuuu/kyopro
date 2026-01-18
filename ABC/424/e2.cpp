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
    int t; cin >> t;
    while(t--){
        ll n, k, x; cin >> n >> k >> x;
        vector<long double> a(n);
        rep(i, 0, n) cin >> a[i];
        
        priority_queue<pair<long double, ll>> que;
        rep(i, 0, n) que.push({a[i], 1});
        
        while(k){
            auto [num, cnt] = que.top(); que.pop();
            if(k <= cnt){
                que.push({num/2.0, k*2});
                que.push({num, cnt-k});
                k = 0;
                break;
            }else{
                que.push({num/2.0, cnt*2});
                k -= cnt;
            }
        }

        while(true){
            auto [num, cnt] = que.top(); que.pop();
            if(x <= cnt){
                cout << setprecision(20) << num << endl;
                break;
            }else{
                x -= cnt;
            }
        }
    }
    return 0;
}