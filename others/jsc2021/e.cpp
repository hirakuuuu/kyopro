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

class UnionFind {
    vector<ll> parent;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1){}

    inline bool same(ll x, ll y){
        return root(x) == root(y);
    }

    inline void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return;
        if(parent[rx] > parent[ry]) swap(rx, ry);
        parent[rx] += parent[ry];
        parent[ry] = rx;
    }

    inline ll size(ll x){
        return (-parent[root(x)]);
    }

    inline ll operator[](ll x){
        return root(x);
    }
};

int main(){
    int k; cin >> k;
    string s; cin >> s;
    int n = (int)s.size();

    if(k > 20){
        cout << "impossible" << endl;
        return 0;
    }

    vector<int> dp(n+1);
    dp[0] = 1, dp[1] = 2;
    rep(i, 2, n+1){
        dp[i] = (dp[i/2]<<1)+1;
    }
    if(!(dp[n]&(1<<k))){
        cout << "impossible" << endl;
        return 0;
    }

    // 同じ文字になっていないと行けないところをグループにする
    UnionFind uf(n);
    int lv0_l = -1, lv0_r = -1;
    // [l, r)
    auto dfs = [&](auto self, int l, int r, int lev) -> void {
        if(lev == 0){
            if(lv0_l != -1) return;
            lv0_l = l, lv0_r = r;
            return;
        }
        rep(i, 0, (r-l)/2){
            uf.unite(l+i, r-1-i);
        }
        self(self, l, (l+r)/2, lev-1);
        self(self, (l+r+1)/2, r, lev-1);
    };
    dfs(dfs, 0, n, k);

    vector<vector<int>> cnt(n, vector<int>(26));
    vector<int> mx(n, -1);
    rep(i, 0, n) cnt[uf[i]][s[i]-'a']++;
    string p;
    rep(i, 0, n){
        int maxi = 0, num = -1;
        rep(j, 0, 26){
            if(maxi < cnt[uf[i]][j]){
                maxi = cnt[uf[i]][j];
                num = j;
            }
        }
        mx[i] = maxi;
        p += 'a'+num;
    }
    // [lv0_l, lv0_r) がレベル 0 になるかを判定
    int len = lv0_r-lv0_l;
    bool is_lv0 = (len == 0);
    rep(i, 0, len){
        if(p[lv0_l+i] != p[lv0_r-1-i]) is_lv0 = true;
    }
    if(is_lv0){
        // s と p の差分を取る
        int ans = 0;
        rep(i, 0, n){
            if(s[i] != p[i]) ans++;
        }
        cout << ans << endl;
    }else{
        // [lv0_l, lv0_r) の中央1文字以外を別の文字にする
        int tmp = 0;
        rep(i, 0, n){
            if(s[i] != p[i]) tmp++;
        }
        int ans = IINF;
        rep(i, 0, len){
            if(len%2 && i == len/2) continue;
            sort(cnt[uf[lv0_l+i]].rbegin(), cnt[uf[lv0_l+i]].rend());
            int cur = tmp+cnt[uf[lv0_l+i]][0]-cnt[uf[lv0_l+i]][1];
            chmin(ans, cur);
        }
        cout << ans << endl;
    }

    
    return 0;
}