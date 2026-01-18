#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
- 子孫祖先の関係を表す行列は，隣接行列の一般化になっていると思うと，1になっているところの意味をとらえやす
- 根になるのは全部の頂点に対して１になっているところ
- 部分木にしたときに同じ連結成分にいないといけない
*/

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        rep(i, 0, n){
            rep(j, 0, n){
                cin >> a[i][j];
            }
        }
        // 対称行列
        {
            bool same = true;
            rep(i, 0, n) rep(j, 0, n){
                if(a[i][j] != a[j][i]) same = false;
            }
            if(!same){
                cout << 0 << endl;
                continue;
            }
        }
        // A[1][i], A[i][1] は全部１
        {
            bool ok = true;
            rep(i, 0, n){
                if(a[0][i] == 0) ok = false;
            }
            if(!ok){
                cout << 0 << endl;
                continue;
            }
        }

        vector<vector<int>> to(n);
        rep(u, 1, n) rep(v, u+1, n){
            if(a[u][v] == 1) continue;
            rep(w, 0, n){
                if(a[u][w] == 1 && a[v][w] == 1){
                    to[w].push_back(u);
                    to[w].push_back(v);
                }
            }
        }
        vector<int> ind(n);
        rep(i, 0, n){
            sort(to[i].begin(), to[i].end());
            to[i].erase(unique(to[i].begin(), to[i].end()), to[i].end());
            for(auto j: to[i]) ind[j]++;
        }


        vector<int> topo;
        rep(i, 0, n){
            if(ind[i]) continue;
            queue<int> que;
            que.push(i);
            while(!que.empty()){
                int q = que.front(); que.pop();
                topo.push_back(q);
                for(auto nq: to[q]){
                    ind[nq]--;
                    if(ind[nq] == 0) que.push(nq);
                }
            }
        }
        if(topo.size() < n){
            cout << 0 << endl;
            continue;
        }





    }
    return 0;
}