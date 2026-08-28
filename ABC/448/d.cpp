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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> b(n);
    map<int, int> cnt;
    set<int> st;
    auto f = [&](auto self, int pos, int pre, int depth) -> void {
        cnt[a[pos]]++;
        st.insert(a[pos]);
        if(st.size() != depth) b[pos] = 1;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos, depth+1);
        }
        cnt[a[pos]]--;
        if(cnt[a[pos]] == 0) st.erase(a[pos]);
    };
    f(f, 0, -1, 1);


    st.clear();
    vector<int> ans(n);
    auto f2 = [&](auto self, int pos, int pre) -> void {
        if(b[pos]) st.insert(pos);
        if(!st.empty()) ans[pos] = 1;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
        }
        if(st.count(pos)) st.erase(pos);
    };
    f2(f2, 0, -1);
    rep(i, 0, n){
        if(ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}