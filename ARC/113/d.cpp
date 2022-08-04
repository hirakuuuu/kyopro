#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

// 問題
// https://atcoder.jp/contests/arc113/tasks/arc113_d

/*
(aの最大値)>=(bの最小値)であれば、それを満たすような埋め方はつくれる
https://atcoder.jp/contests/arc113/editorial/709
あとはaの最大値を固定して(A, B)のパターンがいくつ作れるかを考えるだけ
*/

constexpr ll MOD = 998244353;
template <ll MOD> class ModInt {
public:
    ll x = 0;
    static vector<ModInt<MOD>> factorial_dic;
    ModInt(ll x_ = 0){
        x = x_ %MOD;
        if(x < 0) x += MOD;
    }

    friend constexpr istream &operator>>(istream &is, ModInt<MOD> &x){
        is >> x.x;
        x.x %= MOD;
        if(x.x < 0) x.x += MOD;
        return is;
    }

    friend constexpr ostream &operator<<(ostream &os, const ModInt<MOD> &x){
        return os << x.x;
    }

    ModInt<MOD> operator+(const ModInt<MOD> r) const { return ModInt<MOD>(*this) += r; }
    ModInt<MOD> operator-(const ModInt<MOD> r) const { return ModInt<MOD>(*this) -= r; }
    ModInt<MOD> operator*(const ModInt<MOD> r) const { return ModInt<MOD>(*this) *= r; }
    ModInt<MOD> operator/(const ModInt<MOD> r) const { return ModInt<MOD>(*this) /= r; }

    ModInt<MOD> &operator+=(const ModInt<MOD> &r){
        x += r.x;
        if(x >= MOD) x -= MOD;
        return *this;
    }

    ModInt<MOD> &operator-=(const ModInt<MOD> &r){
        x -= r.x;
        if(x < 0) x += MOD;
        return *this;
    }

    ModInt<MOD> &operator*=(const ModInt<MOD> &r){
        x = x*r.x%MOD;
        return *this;
    }

    ModInt<MOD> &operator/=(const ModInt<MOD> &r){
        *this *= inv(r);
        return *this;
    }

    static ModInt<MOD> pow(ModInt<MOD> num, ll exp){
        if(!exp) return ModInt<MOD>(1);
        ModInt<MOD> ret(1);
        ModInt<MOD> tmp = num;
        while(exp){
            if(exp&1) ret *= tmp;
            tmp *= tmp;
            exp >>= 1;
        }
        return ret;
    }

    static ModInt<MOD> combination(ll n, ll r){
        ModInt<MOD> ret = ModInt<MOD>::factorial(n) / ModInt<MOD>::factorial(r) / ModInt<MOD>::factorial(n-r);
        return ret;
    }

    static ModInt<MOD> factorial(ll n){
        ModInt<MOD> ret(1);
        if(n == 0) return ret;
        if((ll)factorial_dic.size() >= n) return factorial_dic[n-1];
        ret = factorial(n-1)*n;
        factorial_dic.push_back(ret);
        return ret;
    }

    static ModInt<MOD> inv(ModInt<MOD> num){
        return ModInt<MOD>::pow(num, MOD-2);
    }
};

using mint = ModInt<MOD>;
template <ll MOD> vector<ModInt<MOD>> ModInt<MOD>::factorial_dic;

int main(){
    ll n, m, k; cin >> n >> m >> k;
    mint ans = 0, k_ = k;
    if(n == 1){
        ans = mint::pow(k, m);
    }else if(m == 1){
        ans = mint::pow(k, n);
    }else{
        rep(i, 1, k+1){
            mint x = i;
            ans += (mint::pow(x, n)-mint::pow(x-1, n))*mint::pow(k_-x+1, m);
        }
    }

    cout << ans << endl;

    
    return 0;
}