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

class UnionFind {
    vector<ll> parent, maxi, mini;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1), maxi(n_), mini(n_){
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }

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
        maxi[rx] = std::max(maxi[rx],maxi[ry]);
        mini[rx] = std::min(mini[rx],mini[ry]);
    }

    inline ll min(ll x){
        return mini[root(x)];
    }

    inline ll max(int x){
        return maxi[root(x)];
    }

    inline ll size(ll x){
        return (-parent[root(x)]);
    }

    inline ll operator[](ll x){
        return root(x);
    }

    inline void print(){
        rep(i, 0, (ll)parent.size()) cout << root(i) << " ";
        cout << endl;
    }

    void clear(){
        rep(i, 0, (ll)parent.size()){
            parent[i] = -1;
        }
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }
};

const int vmax = 250005; // ここは問題ごとに考慮が必要
mint fact[vmax], finv[vmax];
void initfact(){
	fact[0]= 1;
	for(int i = 1; i < vmax; i++) fact[i] = fact[i-1]*i; // 階乗の計算
	finv[vmax-1] = fact[vmax-1].inv();
	for(int i = vmax-2; i >=0; i--) finv[i] = finv[i+1]*(i+1); // 階乗の逆元
}
// nCk
mint choose(int n,int k){
    if(n < 0 || k < 0 || n < k) return 0;
    if(n == 0 && k == 0) return 1;
	return fact[n]*finv[n-k]*finv[k];
}
// (a+b)!/(a!b!)
mint binom(int a,int b){
	return 0<=a&&0<=b?fact[a+b]*finv[a]*finv[b]:0;
}
// カタラン数（括弧列とか）
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}
// 重複組み合わせ
mint homogeneous(int n, int k){
    return choose(n+k-1, k);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initfact();

    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> a(m), b(m);
    UnionFind uf(n);
    rep(i, 0, m){
        cin >> a[i] >> b[i]; a[i]--, b[i]--;
        uf.unite(a[i], b[i]);
    }

    vector<vector<int>> cnt(n, vector<int>(26));
    bool same = false;
    rep(i, 0, n){
        cnt[uf[i]][s[i]-'a']++;
        if(cnt[uf[i]][s[i]-'a'] == 2) same = true;
    }

    if(same){
        mint ans = 1;
        rep(i, 0, n){
            if(i != uf[i]) continue;
            mint tmp = 1;
            int tot = 0;
            rep(j, 0, 26){
                if(cnt[i][j] > 0){
                    tmp /= fact[cnt[i][j]];
                    tot += cnt[i][j];
                }
            }
            tmp *= fact[tot];
            ans *= tmp;
        }
        cout << ans.val() << endl;
    }else{
        mint ans = 1;
        rep(i, 0, n){
            if(i != uf[i]) continue;
            mint tmp = 1;
            int tot = 0;
            rep(j, 0, 26){
                if(cnt[i][j] > 0){
                    tmp /= fact[cnt[i][j]];
                    tot += cnt[i][j];
                }
            }
            if(tot == 1) continue;
            tmp *= fact[tot];
            ans *= tmp;
        }
        ans /= 2;
        cout << ans.val() << endl;
    }





    
    return 0;
}