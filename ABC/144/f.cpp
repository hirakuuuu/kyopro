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
1本塞いだときの期待値の変化は (スタートから到達する確率)*(ゴールに到達する期待値) の変化を考えてあげれば良い
*/

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n), rev(n);
    vector<int> s(m), t(m);
    rep(i, 0, m){
        cin >> s[i] >> t[i];
        s[i]--, t[i]--;
        g[s[i]].push_back(t[i]);
        rev[t[i]].push_back(s[i]);
    }

    vector<long double> p(n);
    p[0] = 1.0;
    rep(i, 0, n){
        for(auto nxt: g[i]){
            p[nxt] += p[i]/(g[i].size());
        }
    }

    vector<vector<long double>> e(n, vector<long double>(n));
    vector<long double> e_sum(n); // n-1 に到達する時の期待値*(通り数)
    rrep(goal, n-1, 0){
        e[goal][goal] = 0.0;
        if(goal == n-1) e_sum[n-1] = 0.0;
        rrep(i, goal-1, 0){
            for(auto nxt: g[i]){
                e[goal][i] += 1.0+e[goal][nxt];
                if(goal == n-1) e_sum[i] += 1.0+e[n-1][nxt];
            }
            e[goal][i] /= g[i].size();
        }
    }
    long double ans = e[n-1][0];
    rep(i, 0, m){
        if(g[s[i]].size() == 1) continue;
        long double tmp = e[n-1][0]-(p[s[i]]/g[s[i]].size())*e_sum[s[i]];
        tmp += (p[s[i]]/(g[s[i]].size()-1))*(e_sum[s[i]]-(1.0+e[n-1][t[i]]));
        chmin(ans, tmp);
    }
    cout << setprecision(20) << ans << endl;


    return 0;
}