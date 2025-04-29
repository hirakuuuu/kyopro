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
    vector<ll> x(n), y(n);
    vector<ll> p(n);
    rep(i, 0, n){
        cin >> x[i] >> y[i] >> p[i];
    }

    ll ng = 0, ok = 4004004004;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        vector<vector<int>> g(n);
        rep(i, 0, n){
            rep(j, 0, n){
                if(i == j) continue;
                if(mid*p[i] >= abs(x[i]-x[j])+abs(y[i]-y[j])){
                    g[i].push_back(j);
                }
            }
        }

        bool flag = false;
        rep(i, 0, n){
            queue<int> que;
            que.push(i);
            vector<bool> seen(n);
            seen[i] = true;
            while(!que.empty()){
                int q = que.front(); que.pop();
                for(auto nq: g[q]){
                    if(seen[nq]) continue;
                    seen[nq] = true;
                    que.push(nq);
                }
            }
            bool f = true;
            rep(j, 0, n){
                f &= seen[j];
            }
            if(f) flag = true;
        }
        if(flag) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}
