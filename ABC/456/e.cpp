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
        vector<int> u(m), v(m);
        rep(i, 0, m){
            cin >> u[i] >> v[i];
            u[i]--, v[i]--;
        }

        int w; cin >> w;
        vector<string> s(n);
        rep(i, 0, n) cin >> s[i];

        vector<vector<int>> g(n*w);
        vector<vector<int>> rev(n*w);
        vector<int> outdeg(n*w);
        rep(i, 0, n){
            rep(j, 0, w){
                if(s[i][j] == 'o' && s[i][(j+1)%w] == 'o'){
                    g[i*w+j].push_back(i*w+(j+1)%w);
                    rev[i*w+(j+1)%w].push_back(i*w+j);
                    outdeg[i*w+j]++;
                }
            }
        }
        rep(i, 0, m){
            rep(j, 0, w){
                if(s[u[i]][j] == 'o' && s[v[i]][(j+1)%w] == 'o'){
                    g[u[i]*w+j].push_back(v[i]*w+(j+1)%w);
                    rev[v[i]*w+(j+1)%w].push_back(u[i]*w+j);
                    outdeg[u[i]*w+j]++;
                }
                if(s[v[i]][j] == 'o' && s[u[i]][(j+1)%w] == 'o'){
                    g[v[i]*w+j].push_back(u[i]*w+(j+1)%w);
                    rev[u[i]*w+(j+1)%w].push_back(v[i]*w+j);
                    outdeg[v[i]*w+j]++;
                }
            }
        }

        queue<int> que;
        rep(i, 0, n*w){
            if(outdeg[i] == 0) que.push(i);
        }
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: rev[q]){
                outdeg[nq]--;
                if(outdeg[nq] == 0) que.push(nq);
            }
        }

        bool ok = false;
        rep(i, 0, n){
            if(s[i][0] == 'x') continue;
            if(outdeg[i*w]) ok = true;
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}