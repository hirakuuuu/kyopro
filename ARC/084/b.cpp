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
- k = 2^i*5^j → 1 が達成可能　(10^max(i, j) が k の倍数)
- 余りと桁和をもってDP？
*/

int main(){
    int k; cin >> k;
    auto f = [&](int n) -> int {
        int res = 0;
        while(n){
            res += n%10;
            n /= 10;
        }
        return res;
    };

    int mx = f(k);
    vector<vector<bool>> seen(k, vector<bool>(mx+1));
    queue<pair<int, int>> que;
    que.push({0, 0});
    seen[0][0] = true;
    while(!que.empty()){
        auto [m, s] = que.front(); que.pop();
        rep(l, 0, 10){
            int nm = (m*10+l)%k, ns = s+l;
            if(ns > mx) continue;
            if(seen[nm][ns]) continue;
            seen[nm][ns] = true;
            que.push({nm, ns});
        }
    }

    rep(i, 1, mx+1){
        if(seen[0][i]){
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}