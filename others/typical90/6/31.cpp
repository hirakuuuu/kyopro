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


int main(){
    int n; cin >> n;
    vector<int> w(n), b(n);
    rep(i, 0, n) cin >> w[i];
    rep(i, 0, n) cin >> b[i];

    vector<vector<int>> g(51, vector<int>(1500, -1));
    auto f = [&](auto self, int W, int B) -> int {
        if(g[W][B] != -1) return g[W][B];
        if(W == 0 && B <= 1) return g[W][B] = 0;
        set<int> s;
        if(W >= 1){
            s.insert(self(self, W-1, B+W));
        }
        if(B >= 2){
            rep(k, 1, B/2+1){
                s.insert(self(self, W, B-k));
            }
        }
        g[W][B] = 0;
        while(s.count(g[W][B])) g[W][B]++;
        return g[W][B];
    };
    int ans = 0;
    rep(i, 0, n){
        ans ^= f(f, w[i], b[i]);
    }
    if(ans) cout << "First" << endl;
    else cout << "Second" << endl;
    



    return 0;
}