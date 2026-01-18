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
    int h, w, n; cin >> h >> w >> n;

    vector<set<int>> r(h), c(w);
    rep(i, 0, n){
        int x, y; cin >> x >> y;
        x--, y--;
        r[x].insert(y);
        c[y].insert(x);
    }

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x; x--;
            cout << r[x].size() << endl;
            for(auto cc: r[x]){
                c[cc].erase(x);
            }
            r[x].clear();
        }else{
            int y; cin >> y; y--;
            cout << c[y].size() << endl;
            for(auto rr: c[y]){
                r[rr].erase(y);
            }
            c[y].clear();
        }
    }
    
    return 0;
}