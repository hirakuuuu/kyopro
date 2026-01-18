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

/*
- 残っているやつで xor 基底があれば作れる
*/



int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(m);
    vector<bool> in_a(n);
    rep(i, 0, m){
        cin >> a[i];
        in_a[a[i]] = true;
    }
    
    vector<ll> b;
    vector<bool> able(n);
    able[0] = true;
    rep(i, 1, n){
        if(in_a[i]) continue;
        if(able[i]) continue;
        b.push_back(i);
        vector<bool> _able = able;
        rep(j, 0, n){
            if(_able[j]) able[(j^i)] = true;
        }
    }

    if((1<<b.size()) != n){
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int, int>> edges;
    vector<int> seen(n);
    queue<int> que;
    que.push(0);
    seen[0] = true;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto bb: b){
            int nq = (q^bb);
            if(seen[nq]) continue;
            que.push(nq);
            edges.push_back({q, nq});
            seen[nq] = 1;
        }
    }

    if((int)edges.size() != n-1){
        cout << -1 << endl;
    }else{
        rep(i, 0, n-1){
            cout << edges[i].first << ' ' << edges[i].second << endl;
        }
    }


    return 0;
}