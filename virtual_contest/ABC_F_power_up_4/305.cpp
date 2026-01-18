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
    int n, m; cin >> n >> m;

    vector<int> par(n, -1);
    par[0] = 0;
    auto f = [&](auto self, int pos) -> void {
        if(pos == n-1){
            string ok; cin >> ok;
            exit(0);
        }
        int k; cin >> k;
        int nxt = -1;
        rep(i, 0, k){
            int v; cin >> v; v--;
            if(nxt == -1 && par[v] == -1){
                par[v] = pos;
                nxt = v;
            }
        }
        if(nxt != -1){
            cout << nxt+1 << endl;
            self(self, nxt);
        }else{
            cout << par[pos]+1 << endl;
            self(self, par[pos]);
        }
        return;
    };
    f(f, 0);
    return 0;
}