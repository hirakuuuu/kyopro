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
// https://atcoder.jp/contests/abc235/tasks/abc235_f

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
    string s; cin >> s;
    int n = (int)s.size();
    int m; cin >> m;
    int c = 0;
    rep(i, 0, m){
        int C; cin >> C;
        c += 1<<C;
    }

    vector<vector<mint>> sum(n+1, vector<mint>(1<<10)); // n より小さい数
    vector<mint> sum_(n+1); // n と等しい数
    vector<vector<mint>> cnt(n+1, vector<mint>(1<<10)); // n より小さい数
    int f = 0;
    rep(i, 1, n+1){
        rep(j, 0, 10){
            if(s[i-1]-'0' == j){
                sum_[i] += sum_[i-1]*10+j;
                rep(k, 0, 1<<10){
                    sum[i][k|(1<<j)] += sum[i-1][k]*10+cnt[i-1][k]*j;
                    cnt[i][k|(1<<j)] += cnt[i-1][k];
                }
            }else if(s[i-1]-'0' < j){
                rep(k, 0, 1<<10){
                    sum[i][k|(1<<j)] += sum[i-1][k]*10+cnt[i-1][k]*j;
                    cnt[i][k|(1<<j)] += cnt[i-1][k];
                }
            }else{
                rep(k, 0, 1<<10){
                    sum[i][k|(1<<j)] += sum[i-1][k]*10+cnt[i-1][k]*j;
                    cnt[i][k|(1<<j)] += cnt[i-1][k];
                }
                if((f|(1<<j)) == 1) continue;
                sum[i][f|(1<<j)] += sum_[i-1]*10+j;
                cnt[i][f|(1<<j)] += 1;
            }
        }
        if(f > 0 && i > 1){
            rep(j, 1, 10){
                sum[i][(1<<j)] += j;
                cnt[i][(1<<j)] += 1;
            }
        }
        f |= (1<<(s[i-1]-'0'));
        mint ans = 0;
        rep(j, 0, (1<<10)){
            if((j&c) == c){
                ans += sum[i][j];
            }
        }
        // cout << sum_[i] << ' ' << ans << endl;
    }

    mint ans = 0;
    if((f&c) == c) ans += sum_[n];
    rep(i, 0, (1<<10)){
        if((i&c) == c){
            ans += sum[n][i];
        }
    }
    cout << ans << endl;


    
    return 0;
}