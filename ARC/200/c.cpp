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
        int n; cin >> n;
        vector<int> l(n), r(n);
        rep(i, 0, n) cin >> l[i] >> r[i];
        // vector<vector<int>> g(n);
        vector<vector<int>> rev(n);
        vector<int> deg(n);
        rep(i, 0, n) rep(j, 0, n){
            if(i == j) continue;
            if(l[i] < l[j] && r[j] < r[i]){
                // g[j].push_back(i);
                rev[i].push_back(j);
                deg[i]++;
            }
        }

        vector<int> ans(n);
        auto f = [&](auto self, vector<bool> v, int off) -> void {
            // v の中で最小の頂点を求める
            int mi = n;
            rep(i, 0, n){
                if(v[i]){
                    mi = i;
                    break;
                }
            }
            if(mi == n) return; // 頂点が空の場合

            // mi から到達できる頂点をすべて列挙
            vector<bool> a(n), b(n);
            queue<int> que;
            que.push(mi);
            a[mi] = true;
            int cnt = 0;
            while(!que.empty()){
                int q = que.front(); que.pop();
                for(auto nq: rev[q]){
                    if(!v[nq]) continue;
                    if(a[nq]) continue;
                    a[nq] = true;
                    cnt++;
                    que.push(nq);
                }
            }
            ans[mi] = cnt+off;
            rep(i, 0, n){
                if(!v[i]) continue;
                if(a[i]) continue;
                b[i] = true;
            }
            a[mi] = false;
            self(self, a, off);
            self(self, b, off+cnt+1);
        };

        f(f, vector<bool>(n, true), 0);
        rep(i, 0, n){
            cout << ans[i]+1 << ' ';
        }
        cout << endl;

    }
    return 0;
}