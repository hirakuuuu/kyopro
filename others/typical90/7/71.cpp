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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    cin.tie(0);
	ios_base::sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n);
    vector<int> ind(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        ind[b]++;
    }

    vector<int> stc;
    rep(i, 0, n) if(ind[i] == 0) stc.push_back(i);
    vector<vector<int>> ans;
    vector<int> p(n, -1);
    auto dfs = [&](auto self, int d) -> bool{
        if(d == n){
            ans.push_back(p);
            return true;
        }
        if(stc.empty()){
            return false;
        }
        // ここを後ろから見るようにしただけで、かなり早くなった
        rrep(i, stc.size()-1, 0){
            if(ans.size() == k) break;
            int q = stc[i];
            stc.erase(stc.begin()+i);
            for(auto nq: g[q]){
                ind[nq]--;
                if(ind[nq] == 0){
                    stc.push_back(nq);
                }
            }
            p[d] = q;
            bool f = self(self, d+1);
            if(!f){
                return false;
            }
            p[d] = -1; 
            for(auto nq: g[q]){
                if(ind[nq] == 0){
                    stc.pop_back();
                }
                ind[nq]++;
            }
            stc.insert(stc.begin()+i, q);
        }
        return true;
    };
    dfs(dfs, 0);
    if(ans.size() < k){
        cout << -1 << endl;
        return 0;
    }
    for(auto aa: ans){
        for(auto a: aa){
            cout << a+1 << ' ';
        }
        cout << endl;
    }
    return 0;
}