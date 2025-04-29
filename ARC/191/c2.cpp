#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

constexpr ll MOD = 256;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
- A と M は互いに素
- 
*/

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

// 素数 p の原始根を一つ得る 計算量 O(p^(1/4))
ll find_primitive_root(ll p) {
	if (p == 2) return 1LL;

	mt19937_64 mt((int)time(NULL));
	uniform_int_distribution<ll> rnd(1, p - 1);

	// p-1 の素因数を得る．
	auto factors = prime_factorization(p-1);

	while (true) {
		// 原始根の候補をランダムに選ぶ
		ll r = rnd(mt);

		// p-1 の任意の素因数 q について r^((p-1)/q) が 1 でないことが
		// r が原始根であるための必要十分条件となる．
		bool ok = true;
		for (auto [q, e]: factors) {
			if (mod_pow(r, (p-1)/q, p) == 1) {
				ok = false;
				break;
			}
		}
		if(ok) return r;
	}
	return -1;
}

int main(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        rep(k, 2, 1000){
            ll m = n*k+1;
            if(!miller_rabin(m)) continue;
            ll pr = find_primitive_root(m);
            cout << mod_pow(pr, k, m) << ' ' << m << endl;
            break;
        }
    }

    return 0;
}