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
        int n, m; cin >> n >> m;
        vector<vector<pair<int, int>>> g(n);
        rep(i, 0, m){
            int a, b; cin >> a >> b; a--, b--;
            int x; cin >> x;
            g[a].push_back({b, x});
            g[b].push_back({a, x});
        }

        int tot = 0;
        rep(i, 0, n+1) tot ^= i;

        queue<int> que;
        vector<int> v(n, -1);
        que.push(0);
        v[0] = 0;
        while(!que.empty()){
            int q = que.front(); que.pop(); 
            for(auto [nq, x]: g[q]){
                if(v[nq] != -1){
                    assert(v[nq] == v[q]^x);
                    continue;
                }
                v[nq] = v[q]^x;
                que.push(nq);
            }
        }

        int tmp = 0;
        rep(i, 0, n) tmp ^= v[i];
        if(n%2 == 0){
            cout << (tot^tmp) << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}