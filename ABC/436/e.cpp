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
    vector<int> p(n);
    rep(i, 0, n){
        cin >> p[i]; p[i]--;
    }

    vector<vector<int>> g;
    vector<int> seen(n);
    rep(i, 0, n){
        if(seen[i]) continue;
        g.push_back({});
        int pos = i;
        queue<int> que;
        que.push(pos);
        while(!seen[pos]){
            seen[pos] = true;
            g.back().push_back(pos);
            pos = p[pos];
        }
    }

    ll ans = 0;
    for(auto c: g){
        ll len = c.size();
        ans += len*(len-1)/2;
    }
    cout << ans << endl;
    
    return 0;
}