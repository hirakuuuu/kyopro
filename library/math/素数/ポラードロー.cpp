#include <bits/stdc++.h>
using namespace std;

#define ll long long



// ミラー・ラビン素数判定法
// p を奇素数とすると，任意の a∈[1..p) についてフェルマーの小定理より
//		a^(p-1) ≡ 1 (mod p)
// となる．これの平方根を考えていくと，
//		p-1 = 2^s d　（d : 奇数）
// と表せば，
//		a^d ≡ 1 (mod p) or ∃r=[0..s), a^(2^r d) ≡ -1 (mod p)
// と書き直せる．
// 
// この対偶を用いて判定することをランダムに選んだ a で繰り返す．
// n < 2^64 に範囲を限定するなら擬素数を生じない a を固定的に選べる．
// a = {2, 325, 9375, 28178, 450775, 9780504, 1795265022} と取ればよい.
// https://miller-rabin.appspot.com


// reference : https://nyaannyaan.github.io/library/prime/fast-factorize.hpp.html

// 64 bit で mod を取る
ll mod_pow(ll a, ll b, ll m){
    ll res = 1;
    a %= m;
    while(b > 0){
        if(b&1) res = __uint128_t(res)*a%m;
        a = __uint128_t(a)*a%m;
        b >>= 1;
    }
    return res;
}


// num が素数なら true，そうでなければ false （計算量 O(log{num}^3)）
bool miller_rabin(ll num){
    const vector<ll> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    // これらは例外的に判定が必要（なぜかは分からん）
	if (num == 2 || num == 3 || num == 5 || num == 13 || num == 19 || num == 73 || num == 193
		|| num == 407521 || num == 299210837) return true;
    // 1 か 2 以外の偶数は素数でない
    if(num == 1 || !(num&1)) return false;
    
    // num-1 = 2^s d (d は奇数) を満たす s, d を求める
    ll s = 0, d = num-1;
    while(!(d&1)){
        s = s+1, d >>= 1;
    }

    // 各 a について，条件をチェックする
    for(auto a: A){
        ll powa = mod_pow(a, d, num);
        if(powa == 1 || powa == num-1) continue;
        
        bool may_prime = false;
        for(int i = 0; i < s-1; i++){
            powa = __uint128_t(powa)*powa%num;
            if(powa == 1) return false;
            if(powa == num-1){
                may_prime = true;
                break;
            }
        }
        if(!may_prime) return false;
    }

    return true;
}

//　素因数検出 O(n^(1/4))
ll find_prime_factor(ll n){

    // 偶数なら 2 を返す
    if(!(n&1)) return 2;
    // n が素数なら n 自身を返す
    if(miller_rabin(n)) return n;

    const int m = 1<<((63-__builtin_clzll(n))/8);
    const int c_max = 100;
    ll res = -1;
    for(ll c = 1; c < c_max; c++){
        // 有限体上の疑似乱数
        auto f = [&](ll x) -> ll { return (__uint128_t(x)*x+c)%n; };

        ll x = 2, y = 2, y_back;
        ll g = 1, q = 1;
        int r = 1, k = 0;
        while(g == 1){
            // x, y を r = 2^i だけ進める
            x = y;
            while(k < 3*r/4){
                y = f(y), k++;
            }
            while(k < r && g == 1){
                y_back = y; // バックトラック用
                
                // m 回まとめて GCD を計算，GCD > 1 となったら途中で抜ける
                for(int i = 0; i < min(m, r-k); i++){
                    y = f(y);
                    q = __uint128_t(q)*abs(x-y)%n;
                }
                g = gcd(q, n);
                k += m;
            }
            k = r;
            r *= 2;
        }

        if(g == n){ // GCD が n であればバックトラックして一つずつ gcd(|x-y|, n) == 1 を検証
            g = 1;
            y = y_back;
            while(g == 1){
                y = f(y);
                g = gcd(abs(x-y), n);
            }
        }

        // gcd(|x-y|, n) = n であれば c の値を変えてもう一回
        if(g == n) continue;

        if(miller_rabin(g)) return g;
        if(miller_rabin(n/g)) return n/g;

        res = find_prime_factor(g);
        if(res != -1) break;
    }
    return res;
}

// 素因数分解 計算量 O(n^{1/4})
// {素数, 指数} で格納
map<ll, int> prime_factorization(ll n){
    map<ll, int> factors;
    if(n == 1) return factors;

    queue<ll> divs;
    divs.push(n);
    while(!divs.empty()){
        ll d = divs.front(); divs.pop();

        if(miller_rabin(d)){
            factors[d]++;
        }else{
            ll d1 = find_prime_factor(d);
            ll d2 = d/d1;
            divs.push(d1);
            divs.push(d2);
        }
    }
    return factors;
}


// verify: https://judge.yosupo.jp/problem/factorize
int main(){
    int q; cin >> q;
    while(q--){
        ll n; cin >> n;
        auto factors = prime_factorization(n);
        
        int tot = 0;
        vector<ll> primes;
        for(auto [p, e]: factors){
            tot += e;
            while(e--) primes.push_back(p);
        }

        sort(primes.begin(), primes.end());
        cout << tot << ' ';
        for(auto p: primes){
            cout << p << ' ';
        }
        cout << endl;
    }
    
    return 0;
}