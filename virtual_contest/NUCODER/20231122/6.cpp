#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

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
        maxi[x] = std::max(maxi[x],maxi[y]);
        mini[x] = std::min(mini[x],mini[y]);
    }

    inline ll min(ll x){
        return mini[root(x)];
    }

    inline ll max(int x){
        return mini[root(x)];
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

template <ll MOD> class modint {
    ll val;
    static vector<modint<MOD>> factorial_vec;
public:
    // コンストラクタ
    modint(ll x = 0){
        val = x % MOD;
        if(val < 0) x += MOD;
    }

    // 入出力ストリーム
    friend constexpr istream &operator>>(istream &is, modint<MOD> &x){
        ll y; is >> y;
        x = y;
        return is;
    }
    friend constexpr ostream &operator<<(ostream &os, const modint<MOD> &x){
        return os << x.val;
    }

    // 算術演算子
    modint<MOD> operator -(){return modint<MOD>(-val);}
    modint<MOD> operator +(const modint<MOD> &r) const { return modint<MOD>(*this) += r; }
    modint<MOD> operator -(const modint<MOD> &r) const { return modint<MOD>(*this) -= r; }
    modint<MOD> operator *(const modint<MOD> &r) const { return modint<MOD>(*this) *= r; }
    modint<MOD> operator /(const modint<MOD> &r) const { return modint<MOD>(*this) /= r; }

    // 代入演算子
    modint<MOD> &operator +=(const modint<MOD> &r){
        val += r.val;
        if(val >= MOD) val -= MOD;
        return *this;
    }
    modint<MOD> &operator -=(const modint<MOD> &r){
        if(val < r.val) val += MOD;
        val -= r.val;
        return *this;
    }
    modint<MOD> &operator *=(const modint<MOD> &r){
        val = val*r.val%MOD;
        if(val < 0) val += MOD;
        return *this;
    }
    modint<MOD> &operator /=(const modint<MOD> &r){
        *this *= inv(r);
        return *this;
    }

    //等価比較演算子
    bool operator ==(const modint<MOD>& r){return this -> val == r.val;}
    bool operator !=(const modint<MOD>& r){return this -> val != r.val;}
    bool operator <(const modint<MOD>& r){return this -> val < r.val;}
    bool operator <=(const modint<MOD>& r){return this -> val <= r.val;}
    bool operator >(const modint<MOD>& r){return this -> val > r.val;}
    bool operator >=(const modint<MOD>& r){return this -> val >= r.val;}

    // 累乗
    static modint<MOD> modpow(modint<MOD> num, ll exp){
        if(!exp) return modint<MOD>(1); // 0乗
        modint<MOD> ret(1);
        modint<MOD> tmp = num;
        while(exp){
            if(exp&1) ret *= tmp;
            tmp *= tmp;
            exp >>= 1;
        }
        return ret;
    }

    // 逆元
    static modint<MOD> inv(modint<MOD> num){
        return modpow(num, MOD-2);
    }

    // 階乗
    static modint<MOD> factorial(ll n){
        modint<MOD> ret(1);
        if(n == 0) return ret;
        if((ll)factorial_vec.size() >= n) return factorial_vec[n-1];
        ret = factorial(n-1)*n;
        factorial_vec.push_back(ret);
        return ret;
    }

    // コンビネーション
    static modint<MOD> combination(ll n, ll r){
        return factorial(n) / factorial(r) / factorial(n-r);
    }

};

using mint = modint<MOD>;
template <ll MOD> vector<modint<MOD>> modint<MOD>::factorial_vec;

const int vmax = 250005;
mint fact[vmax],finv[vmax],invs[vmax];
void initfact(){
	fact[0]=1;
	rep(i,1,vmax){
		fact[i]=fact[i-1]*i;
	}
	finv[vmax-1]=mint::inv(fact[vmax-1]);
	for(int i=vmax-2;i>=0;i--){
		finv[i]=finv[i+1]*(i+1);
	}
	for(int i=vmax-1;i>=1;i--){
		invs[i]=finv[i]*fact[i-1];
	}
}
mint choose(int n,int k){
	return n-k >= 0?fact[n]*finv[n-k]*finv[k]:0;
}
mint binom(int a,int b){
	return 0<=a&&0<=b?fact[a+b]*finv[a]*finv[b]:0;
}
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}

int main(){
    int n; cin >> n;
    vector<int> p(n), q(n);
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
    }
    rep(i, 0, n){
        cin >> q[i];
        q[i]--;
    }

    UnionFind uf(n);
    rep(i, 0, n) uf.unite(p[i], q[i]);

    vector<int> seen(n), g;
    rep(i, 0, n){
        if(seen[uf[i]]) continue;
        seen[uf[i]] = 1;
        g.push_back(uf.size(i));
    }

    vector<vector<mint>> dp(n+1, vector<mint>(2));
    vector<vector<mint>> dp_(n+1, vector<mint>(2));
    dp[1][0] = dp_[1][1] = 1;
    rep(i, 2, n+1){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][0]+dp[i-1][1];
        dp_[i][0] = dp_[i-1][1];
        dp_[i][1] = dp_[i-1][0]+dp_[i-1][1];
    }
    vector<mint> cnt(n+1);
    rep(i, 1, n+1){
        cnt[i] = dp[i][1]+dp_[i][0]+dp_[i][1];
    }

    mint ans = 1;
    for(auto gg: g){
        ans *= cnt[gg];
    }
    cout << ans << endl;


    
    
    return 0;
}