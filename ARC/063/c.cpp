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
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int k; cin >> k;
    vector<int> num(n, -IINF);
    rep(i, 0, k){
        int v, p; cin >> v >> p; v--;
        num[v] = p;
    }

    bool ok = true;
    vector<pair<int, int>> lr(n, {-IINF, IINF});
    auto f = [&](auto self, int pos, int pre) -> void {
        // cout << pos << ' ' << pre << endl;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            chmax(lr[pos].first, lr[nxt].first-1);
            chmin(lr[pos].second, lr[nxt].second+1);
        }
        if(lr[pos].first > lr[pos].second){
            ok = false;
        }else if(num[pos] != -IINF && !inr(lr[pos].first, num[pos], lr[pos].second+1)){
            ok = false;
        }
        if(num[pos] != -IINF){
            lr[pos] = {num[pos], num[pos]};
        }
        return;
    };
    f(f, 0, -1);

    queue<int> que;
    vector<int> seen(n);
    que.push(0);
    seen[0] = 1;
    if(num[0] == -IINF) num[0] = lr[0].first;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(seen[nq]) continue;
            seen[nq] = 1;
            if(num[nq] == -IINF){
                if(inr(lr[nq].first, num[q]+1, lr[nq].second+1)){
                    num[nq] = num[q]+1;
                }else if(inr(lr[nq].first, num[q]-1, lr[nq].second+1)){
                    num[nq] = num[q]-1;
                }else{
                    ok = false;
                }
            }
            que.push(nq);
        }
    }
    if(!ok){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    rep(i, 0, n){
        cout << num[i] << endl;
    }
    
    
    return 0;
}