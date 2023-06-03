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
// https://atcoder.jp/contests/abc304/tasks/abc304_c

int main(){
    ll n, d; cin >> n >> d;
    vector<ll> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    vector<vector<ll>> g(n);
    rep(i, 0, n){
        rep(j, i+1, n){
            if((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) <= d*d){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    queue<int> que;
    que.push(0);
    vector<bool> virus(n);
    virus[0] = true;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(virus[nq]) continue;
            virus[nq] = true;
            que.push(nq);
        }
    }

    rep(i, 0, n){
        if(virus[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}