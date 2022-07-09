#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

constexpr long long MOD = 998244353;
template <long long MOD> class ModInt {
public:
    long long x = 0;
    static vector<ModInt<MOD>> factorial_dic;
    ModInt(long long _x = 0) {
        x = _x % MOD;
        if(x < 0) { x += MOD; }
    }

    friend constexpr istream &operator>>(istream &is, ModInt<MOD> &x) {
        is >> x.x;
        x.x %= MOD;
        if(x.x < 0) { x.x += MOD; }
        return is;
    }
    friend constexpr ostream &operator<<(ostream &os, const ModInt<MOD> &x) { return os << x.x; }

    ModInt<MOD> &operator=(const long long _x) {
        *this = ModInt(_x);
        return *this;
    }

    ModInt<MOD> operator+(const ModInt<MOD> r) const { return ModInt<MOD>(*this) += r; }
    ModInt<MOD> operator-(const ModInt<MOD> r) const { return ModInt<MOD>(*this) -= r; }
    ModInt<MOD> operator*(const ModInt<MOD> r) const { return ModInt<MOD>(*this) *= r; }
    ModInt<MOD> operator/(const ModInt<MOD> r) const { return ModInt<MOD>(*this) /= r; }

    ModInt<MOD> &operator+=(const ModInt<MOD> &r) {
        x += r.x;
        if(x >= MOD) { x -= MOD; }
        return *this;
    }
    ModInt<MOD> &operator-=(const ModInt<MOD> &r) {
        x -= r.x;
        if(x < 0) { x += MOD; }
        return *this;
    }
    ModInt<MOD> &operator*=(const ModInt<MOD> &r) {
        x = x * r.x % MOD;
        return *this;
    }
    ModInt<MOD> &operator/=(const ModInt<MOD> &r) {
        *this *= inv(r);
        return *this;
    }

    static ModInt<MOD> pow(ModInt<MOD> num, long long exp) {
        if(!exp) { return ModInt<MOD>(1); }
        ModInt<MOD> ret(1);
        ModInt<MOD> tmp = num;
        while(exp) {
            if(exp & 1) { ret *= tmp; }
            tmp *= tmp;
            exp >>= 1;
        }
        return ret;
    }

    static ModInt<MOD> combination(long long n, long long r) {
        ModInt<MOD> ret = ModInt<MOD>::factorial(n) / ModInt<MOD>::factorial(r) / ModInt<MOD>::factorial(n - r);
        return ret;
    }

    static ModInt<MOD> factorial(long long n) {
        ModInt<MOD> ret(1);
        if(n == 0) { return ret; }
        if(factorial_dic.size() >= n) { return factorial_dic[n - 1]; }
        ret = factorial(n - 1) * n;
        factorial_dic.push_back(ret);
        return ret;
    }

    static ModInt<MOD> inv(ModInt<MOD> num) { return ModInt<MOD>::pow(num, MOD - 2); }
};
using mint = ModInt<MOD>;
template <long long MOD> vector<ModInt<MOD>> ModInt<MOD>::factorial_dic;


int main(){
    string infilename = "D";
    string outfilename = "out1.txt";
    ifstream reading_file(infilename);
    ofstream writing_file(outfilename);

    ll n, k;
    
    while(reading_file >> n >> k){
        if(n == 0 and k == 0) break;

        mint ans = 0;
        vector<ll> s(n), t(n), first(n+1), ti(n+1);
        rep(i, 0, n){
            reading_file >> s[i];
        }
        rep(i, 0, n){
            reading_file >> t[i];
            ti[t[i]] = i;
        }

        
        priority_queue<pll> que;
        que.push({-s[0], 0});
        first[n] = 1;

        ll can_cut = 0, must_cut = 0;
        rep(i, 0, n-1){
            if(s[i] < s[i+1]){
                if(ti[s[i]] < ti[s[i+1]]){
                    can_cut++;
                }else{
                    que.push({-s[i+1], i+1});
                    first[i+1] = 1;
                    must_cut++;
                }
            }else{
                if(ti[s[i]] > ti[s[i+1]]){
                    que.push({-s[i+1], i+1});
                    first[i+1] = 1;
                    must_cut++;
                }
            }
        }
        vector<ll> tt(n);
        if(k-1-must_cut >= 0){
            rep(i, 0, n){
                pll q = que.top(); que.pop();
                tt[i] = -q.first;
                if(first[q.second+1] == 0){
                    que.push({-s[q.second+1], q.second+1});
                }
            }
            if(tt == t){
                rep(i, 0, min(can_cut, k-1-must_cut)+1){
                    ans = ans+mint::combination(can_cut, i);
                }
            }
        } 
        writing_file << ans << endl;
    }
    
    return 0;
}