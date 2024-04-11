#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

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

/*
部分点解法
DFSで左上の頂点から埋めていく
再帰の際に、使えない頂点を # で埋める

nが小さいので bitDPを考える
マス (i, j) を埋めるのに必要な情報は前 w+1 マス
O(2^w) なので w <= 17 程度であれば、全部持てる

w <= 24 の解法はあり得る状態のみを持つようにすれば良いが、難しそうなので後で...

*/

vector<int> di = {0, 0, 1, 1, 1};
vector<int> dj = {0, 1, -1, 0, 1};

int main(){
    int h, w; cin >> h >> w;
    vector<string> c(h);
    rep(i, 0, h) cin >> c[i];

    vector<vector<mint>> dp(h*w, vector<mint>(1<<(w+1)));
    dp[0][0] = 1;
    if(c[0][0] == '.'){
        dp[0][0+(1<<w)] = 1;
    }
    rep(i, 1, h*w){
        int x = i/w, y = i%w;
        if(y == 0){
            rep(j, 0, 1<<(w+1)){
                /*
                .....x
                xxxxxx
                o.....
                */
               int tmp = (j&6);
               dp[i][j>>1] += dp[i-1][j];
               if(c[x][y] == '.' && tmp == 0){
                    dp[i][(j>>1)+(1<<w)] += dp[i-1][j];
               }
            }
        }else if(y == w-1){
            rep(j, 0, 1<<(w+1)){
                /*
                ....xx
                xxxxxo
                */
               int tmp = (j&3)+((j>>w)&1);
               dp[i][j>>1] += dp[i-1][j];
               if(c[x][y] == '.' && tmp == 0){
                    dp[i][(j>>1)+(1<<w)] += dp[i-1][j];
               }
            }
        }else{
            rep(j, 0, 1<<(w+1)){
                /*
                .xxxxx
                xxo...
                */
               int tmp = (j&7)+((j>>w)&1);
               dp[i][j>>1] += dp[i-1][j];
               if(c[x][y] == '.' && tmp == 0){
                    dp[i][(j>>1)+(1<<w)] += dp[i-1][j];
               }
            }
        }
    }

    mint ans = 0;
    rep(k, 0, 1<<(w+1)){
        ans += dp[h*w-1][k];
    }
    cout << ans << endl;

    
    return 0;
}