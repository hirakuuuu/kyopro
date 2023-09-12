#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
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

bool valid(string s){
    rep(i, 0, s.size()-2){
        string t = s.substr(i, 3);
        if(t == "AGC" || t == "ACG" || t == "GAC") return false;
    }
    return true;
}

bool valid2(string s){
    rep(i, 0, s.size()-2){
        string t = s.substr(i, 3);
        if(t == "AGC") return false;
    }
    return true;
}

int main(){
    int n; cin >> n;
    string s = "ACGT";
    vector<vector<vector<vector<mint>>>> dp(n+1, vector<vector<vector<mint>>>(4, vector<vector<mint>>(4, vector<mint>(4))));
    rep(i, 0, 4){
        rep(j, 0, 4){
            rep(k, 0, 4){
                string t = {s[i], s[j], s[k]};
                if(t == "AGC" || t == "ACG" || t == "GAC") continue;
                dp[3][i][j][k] = 1;
            }
        }
    }

    rep(m, 4, n+1){
        rep(i, 0, 4){
            rep(j, 0, 4){
                rep(k, 0, 4){
                    rep(l, 0, 4){
                        string t = {s[i], s[j], s[k], s[l]};
                        bool f = valid(t);
                        rep(p, 0, 3){
                            swap(t[p], t[p+1]);
                            f &= valid2(t);
                            swap(t[p], t[p+1]);
                        }
                        if(f) dp[m][j][k][l] += dp[m-1][i][j][k];
                    }
                    string t;

                }
            }
        }
    }
    mint ans = 0;
    rep(i, 0, 4){
        rep(j, 0, 4){
            rep(k, 0, 4){
                ans += dp[n][i][j][k];
            }
        }
    }
    cout << ans << endl;


    return 0;
}