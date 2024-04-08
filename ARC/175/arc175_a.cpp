#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

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
    vector<int> p(n);
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
    }
    string s; cin >> s;
    mint ans = 0;
    // 1人目の行動でどのスプーンをとるかが決まる
    if(s[p[0]] == 'L'){
        // 左側のスプーンをとる
        // 自分の右側の人がまだスプーンをとってないかつ右利きだったら詰み
        vector<bool> picked(n);
        ans = 1;
        rep(i, 0, n){
            if(s[p[i]] == 'R' && !picked[(p[i]+1)%n]){
                cout << 0 << endl;
                return 0;
            }
            if(s[p[i]] == '?' && picked[(p[i]+1)%n]) ans *= 2;
            picked[p[i]] = true;
        }
    }else if(s[p[0]] == 'R'){
        // 右側のスプーンをとる
        // 自分の左側の人がまだスプーンをとってないかつ左利きだったら詰み
        vector<bool> picked(n);
        ans = 1;
        rep(i, 0, n){
            if(s[p[i]] == 'L' && !picked[(p[i]-1+n)%n]){
                cout << 0 << endl;
                return 0;
            }
            if(s[p[i]] == '?' && picked[(p[i]-1+n)%n]) ans *= 2;
            picked[p[i]] = true;
        }
    }else{
        // 左側のスプーンをとる
        // 自分の右側の人がまだスプーンをとってないかつ右利きだったら詰み
        vector<bool> picked(n);
        mint ans_l = 1;
        s[p[0]] = 'L';
        rep(i, 0, n){
            if(s[p[i]] == 'R' && !picked[(p[i]+1)%n]){
                ans_l = 0;
                break;
            }
            if(s[p[i]] == '?' && picked[(p[i]+1)%n]) ans_l *= 2;
            picked[p[i]] = true;
        }
        // 右側のスプーンをとる
        // 自分の左側の人がまだスプーンをとってないかつ左利きだったら詰み
        fill(picked.begin(), picked.end(), false);
        mint ans_r = 1;
        s[p[0]] = 'R';
        rep(i, 0, n){
            if(s[p[i]] == 'L' && !picked[(p[i]-1+n)%n]){
                ans_r = 0;
            }
            if(s[p[i]] == '?' && picked[(p[i]-1+n)%n]) ans_r *= 2;
            picked[p[i]] = true;
        }
        ans = ans_l+ans_r;
    }
    cout << ans << endl;
    return 0;
}