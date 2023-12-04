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
// https://atcoder.jp/contests/abc317/tasks/abc317_f

/*
x1^x2 = x3 となる x1, x2 を上の桁から決めていく
(桁、その時点でのx1をa1で割ったあまり, その時点でのx2をa2で割ったあまり, その時点でのx3をa3で割ったあまり, x1 = n or x1 < n, x2 = n or x2 < n, x3 = n or x3 < n)
*/

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

mint dp[105][20][20][20][5][5][5];

int main(){
    ll n; cin >> n; 
    vector<ll> a(3);
    rep(i, 0, 3) cin >> a[i];
    rep(i, 0, 64) rep(j, 0, a[0]) rep(k, 0, a[1]) rep(l, 0, a[2]) rep(ii, 0, 2) rep(jj, 0, 2) rep(kk, 0, 2){
        dp[i][j][k][l][ii][jj][kk] = 0;
    }
    dp[60][0][0][0][1][1][1] = 1;
    rrep(o, 59, 0){
        // dp[o]
        rep(a1, 0, a[0]){
            rep(a2, 0, a[1]){
                rep(a3, 0, a[2]){
                    // dp[o][a1][a2][a3] 上からo桁目まで決定して, あまりがa1, a2, a3
                    if(((n>>o)&1LL) > 0){
                        // ｎのo桁目が1
                        // 1, 0
                        dp[o][(2*a1+1)%a[0]][(2*a2)%a[1]][(2*a3+1)%a[2]][1][0][0] += dp[o+1][a1][a2][a3][1][1][0]+dp[o+1][a1][a2][a3][1][0][0];
                        dp[o][(2*a1+1)%a[0]][(2*a2)%a[1]][(2*a3+1)%a[2]][1][0][1] += dp[o+1][a1][a2][a3][1][1][1]+dp[o+1][a1][a2][a3][1][0][1];
                        dp[o][(2*a1+1)%a[0]][(2*a2)%a[1]][(2*a3+1)%a[2]][0][0][0] += dp[o+1][a1][a2][a3][0][1][0]+dp[o+1][a1][a2][a3][0][0][0];
                        dp[o][(2*a1+1)%a[0]][(2*a2)%a[1]][(2*a3+1)%a[2]][0][0][1] += dp[o+1][a1][a2][a3][0][1][1]+dp[o+1][a1][a2][a3][0][0][1];
                        // 0, 1
                        dp[o][(2*a1)%a[0]][(2*a2+1)%a[1]][(2*a3+1)%a[2]][0][1][0] += dp[o+1][a1][a2][a3][1][1][0]+dp[o+1][a1][a2][a3][0][1][0];
                        dp[o][(2*a1)%a[0]][(2*a2+1)%a[1]][(2*a3+1)%a[2]][0][1][1] += dp[o+1][a1][a2][a3][1][1][1]+dp[o+1][a1][a2][a3][0][1][1];
                        dp[o][(2*a1)%a[0]][(2*a2+1)%a[1]][(2*a3+1)%a[2]][0][0][0] += dp[o+1][a1][a2][a3][1][0][0]+dp[o+1][a1][a2][a3][0][0][0];
                        dp[o][(2*a1)%a[0]][(2*a2+1)%a[1]][(2*a3+1)%a[2]][0][0][1] += dp[o+1][a1][a2][a3][1][0][1]+dp[o+1][a1][a2][a3][0][0][1];
                        // 1, 1
                        dp[o][(2*a1+1)%a[0]][(2*a2+1)%a[1]][(2*a3)%a[2]][1][1][0] += dp[o+1][a1][a2][a3][1][1][0]+dp[o+1][a1][a2][a3][1][1][1];
                        dp[o][(2*a1+1)%a[0]][(2*a2+1)%a[1]][(2*a3)%a[2]][1][0][0] += dp[o+1][a1][a2][a3][1][0][0]+dp[o+1][a1][a2][a3][1][0][1];
                        dp[o][(2*a1+1)%a[0]][(2*a2+1)%a[1]][(2*a3)%a[2]][0][1][0] += dp[o+1][a1][a2][a3][0][1][0]+dp[o+1][a1][a2][a3][0][1][1];
                        dp[o][(2*a1+1)%a[0]][(2*a2+1)%a[1]][(2*a3)%a[2]][0][0][0] += dp[o+1][a1][a2][a3][0][0][0]+dp[o+1][a1][a2][a3][0][0][1];
                        // 0, 0
                        rep(i, 0, 2) rep(j, 0, 2) rep(k, 0, 2){
                            dp[o][(2*a1)%a[0]][(2*a2)%a[1]][(2*a3)%a[2]][0][0][0] += dp[o+1][a1][a2][a3][i][j][k];
                        }
                    }else{
                        // ｎのo桁目が0
                        // 1, 0
                        dp[o][(2*a1+1)%a[0]][(2*a2)%a[1]][(2*a3+1)%a[2]][0][0][0] += dp[o+1][a1][a2][a3][0][0][0];
                        dp[o][(2*a1+1)%a[0]][(2*a2)%a[1]][(2*a3+1)%a[2]][0][1][0] += dp[o+1][a1][a2][a3][0][1][0];
                        // 0, 1
                        dp[o][(2*a1)%a[0]][(2*a2+1)%a[1]][(2*a3+1)%a[2]][0][0][0] += dp[o+1][a1][a2][a3][0][0][0];
                        dp[o][(2*a1)%a[0]][(2*a2+1)%a[1]][(2*a3+1)%a[2]][1][0][0] += dp[o+1][a1][a2][a3][1][0][0];
                        // 1, 1
                        dp[o][(2*a1+1)%a[0]][(2*a2+1)%a[1]][(2*a3)%a[2]][0][0][0] += dp[o+1][a1][a2][a3][0][0][0];
                        dp[o][(2*a1+1)%a[0]][(2*a2+1)%a[1]][(2*a3)%a[2]][0][0][1] += dp[o+1][a1][a2][a3][0][0][1];
                        // 0, 0
                        rep(i, 0, 2) rep(j, 0, 2) rep(k, 0, 2){
                            dp[o][(2*a1)%a[0]][(2*a2)%a[1]][(2*a3)%a[2]][i][j][k] += dp[o+1][a1][a2][a3][i][j][k];
                        }
                    }
                }
            }
        }
    }

    mint ans = 0;
    rep(i, 0, 2) rep(j, 0, 2) rep(k, 0, 2){
        ans += dp[0][0][0][0][i][j][k];
    }

    // (a1 = a2, a3 = 0) (a1 = a3, a2 = 0) (a2 = a3, a1 = 0) (a1 = a2 = a3 = 0) を引く
    mint elm = n/lcm(a[0], a[1])+n/lcm(a[0], a[2])+n/lcm(a[1], a[2])+1;
    ans -= elm;
    cout << ans << endl;

    return 0;
}