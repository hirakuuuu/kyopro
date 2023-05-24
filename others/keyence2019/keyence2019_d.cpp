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

// 問題
// https://atcoder.jp/contests/keyence2019/tasks/keyence2019_d

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


int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    // a, b でそれぞれ重複があるとアウト
    vector<int> cnt_a(n*m+1), cnt_b(n*m+1);
    rep(i, 0, n) cnt_a[a[i]]++;
    rep(i, 0, m) cnt_b[b[i]]++;
    rep(i, 1, n*m+1){
        if(cnt_a[i] > 1 || cnt_b[i] > 1){
            cout << 0 << endl;
            return 0;
        }
    }

    // 上限値を取得
    vector<int> upper_limit_list, upper_limit_cnt(n*m+1);
    rep(i, 0, n){
        rep(j, 0, m){
            int upper_limit = min(a[i], b[j]);
            upper_limit_list.push_back(upper_limit);
            upper_limit_cnt[upper_limit]++;
        }
    }

    // 上限値を超えないと書き込めない場合はアウト
    sort(upper_limit_list.begin(), upper_limit_list.end());
    rep(i, 0, n*m){
        if(i+1 > upper_limit_list[i]){
            cout << 0 << endl;
            return 0;
        }
    }

    // 書き込み方を数える
    mint ans = 1;
    ll rest = 0;


    rrep(i, n*m, 1){
        if(upper_limit_cnt[i] > 0){
            // 上限値を書き込む位置を決める
            if(cnt_a[i]^cnt_b[i]) ans *= upper_limit_cnt[i];
            rest += upper_limit_cnt[i]-1;
        }else{
            ans *= rest;
            rest--;
        }
    }
    cout << ans << endl;

    return 0;
}