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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<set<int>> cnt_r(n), cnt_c(n);
    set<pair<int, int>> s;

    rep(i, 0, m){
        int r, c; cin >> r >> c; r--, c--;
        for(auto cc: cnt_r[r]){
            s.erase({r, cc});
        }
        cnt_r[r].clear();
        for(auto rr: cnt_c[c]){
            s.erase({rr, c});
        }
        cnt_c[c].clear();
        
        s.insert({r, c});
        cnt_r[r].insert(c);
        cnt_c[c].insert(r);
    }

    cout << s.size() << endl;
    return 0;
}