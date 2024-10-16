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
    ll x; cin >> x;
    vector<ll> y(n+2), z(n+2);
    rep(i, 1, n+1) cin >> y[i] >> z[i];
    y[n+1] = z[n+1] = x;

    // 壁 i, j に対して, i を破壊しないと j が破壊できないという関係を辺 (i -> j)
    // 自己ループも込みで検出できる
    vector<vector<int>> g(n+2);
    vector<int> cnt_indegree(n+2);

    // 0(スタート) からすべての壁（ゴール含め）に辺を張る
    rep(i, 1, n+2){
        g[0].push_back(i);
        cnt_indegree[i]++;
    }
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            // 0, y[i], (z[j] or y[j]) となっていたらだめ
            if(0 < y[i]){
                if(y[i] < z[j] || y[i] < y[j]){
                    g[i].push_back(j);
                    cnt_indegree[j]++;
                }
            }else{
                if(z[j] < y[i] || y[j] < y[i]){
                    g[i].push_back(j);
                    cnt_indegree[j]++;
                }
            }
        }
    }
    // x に対しても辺を張る
    rep(i, 1, n+1){
        // 壁 i を破壊しないと x にたどり着けないという関係
        if(x < y[i]){
            if(y[i] < 0){
                g[i].push_back(n+1);
                cnt_indegree[n+1]++;
            }
        }else{
            if(0 < y[i]){
                g[i].push_back(n+1);
                cnt_indegree[n+1]++;
            }
        }
    }

    auto topological_sort = [&]() -> vector<int> {
        // ソートして格納する配列
        vector<int> a_sorted;
        queue<int> que;

        // 入次数０のノードをキューに追加
        rep(i, 0, n+2){
            if(cnt_indegree[i] == 0){
                que.push(i);
            }
        }

        // 入次数が０になったノードから配列に格納
        while(!que.empty()){
            int q = que.front(); que.pop();
            a_sorted.push_back(q);
            for(auto nq: g[q]){
                // 辺を削除
                cnt_indegree[nq]--;
                // 入次数が０になったらキューに追加
                if(cnt_indegree[nq] == 0) que.push(nq);
            }
        }

        // ソート済みの配列を返す
        return a_sorted;
    };
    vector<int> p = topological_sort();
    if(p.size() < n+2){
        cout << -1 << endl;
        return 0;
    }

    // トポソの順でDP
    vector<ll> dp(n+2, INF);
    vector<int> l(n+2, -1);
    dp[0] = 0;
    l[0] = 0;
    rep(i, 0, n+2){
        rep(m, l[p[i]], i){
            chmin(dp[p[i]], dp[p[m]]+abs(y[p[i]]-z[p[m]])+abs(z[p[m]]-y[p[m]]));
        }
        for(auto nxt: g[p[i]]){
            l[nxt] = i;
        }
        cout << p[i] << ' ' << dp[p[i]] << endl;
    }
    cout << dp[n+1] << endl;


    
    return 0;
}