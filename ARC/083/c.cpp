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
    vector<int> par(n, -1);
    vector<vector<int>> chi(n);
    rep(i, 1, n){
        cin >> par[i];
        par[i]--;
        chi[par[i]].push_back(i);
    }
    vector<int> x(n);
    rep(i, 0, n) cin >> x[i];

    // BFSして、遠い順にする
    vector<int> a;
    {
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int q = que.front(); que.pop();
            a.push_back(q);
            for(auto c: chi[q]){
                que.push(c);
            }
        }
        reverse(a.begin(), a.end());
    }
    vector<pair<int, int>> dp(n);
    rep(i, 0, n){
        vector<int> dp_(x[a[i]]+1, IINF);
        dp_[0] = 0;
        for(auto c: chi[a[i]]){
            vector<int> ndp_(x[a[i]]+1, IINF);
            auto [v1, v2] = dp[c];
            rep(j, 0, x[a[i]]+1){
                if(j+v1 <= x[a[i]]) chmin(ndp_[j+v1], dp_[j]+v2);
                if(j+v2 <= x[a[i]]) chmin(ndp_[j+v2], dp_[j]+v1);
            }
            swap(ndp_, dp_);
        }
        int mi = IINF;
        rep(j, 0, x[a[i]]+1) chmin(mi, dp_[j]);
        if(mi == IINF){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        dp[a[i]] = {x[a[i]], mi};
    }
    cout << "POSSIBLE" << endl;
    return 0;
}