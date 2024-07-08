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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
期待値の線形性を考えると、各頂点が選ばれる確率の総和が求まればよいことがわかる
各頂点が選ばれる確率は、その頂点に到達可能な集合から、その頂点が一番最初に選ばれる確率を考えればよい
それは 1/(集合のサイズ) に等しい
*/


int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    vector<vector<int>> g(n);
    rep(i, 0, n){
        rep(j, 0, n){
            if(s[i][j] == '1') g[i].push_back(j);
        }
    }

    vector<vector<int>> d(n);
    rep(i, 0, n){
        vector<int> seen(n);
        queue<int> que;
        que.push(i);
        seen[i] = 1;
        while(!que.empty()){
            int q = que.front(); que.pop();
            d[q].push_back(i);
            for(auto nq: g[q]){
                if(seen[nq]) continue;
                seen[nq] = 1;
                que.push(nq);
            }
        }
    }

    long double ans = 0.0;
    rep(i, 0, n) ans += 1.0/(long double)(d[i].size());
    cout << setprecision(20) << ans << endl;
    
    
    return 0;
}