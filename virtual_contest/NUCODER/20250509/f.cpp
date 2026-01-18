#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


// 0ならば素数, 0でないなら最小の素因数
vector<int> erat(1000005);
void init_e(){
    rep(i, 2, sqrt(1000005)){
        if(erat[i] == 0){
            for(ll j = i*i; j <= 1000005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

// 素因数分解
// {素数、指数}で格納
vector<pair<ll, ll>> prime_factorization(ll n){
    vector<pair<ll, ll>> primes;
    while(erat[n]){
        int p = erat[n];
        primes.push_back({p, 0});
        while(n%p == 0){
            primes.back().second++;
            n /= p;
        }
    }
    if(n > 1) primes.push_back({n, 1});
    return primes;
}


int main(){
    init_e();
    int n; cin >> n;

    int tot = 0;
    rep(i, 0, n){
        ll a; cin >> a;
        vector<pair<ll, ll>> pf = prime_factorization(a);
        int tmp = 0;
        for(auto [p, e]: pf) tmp += e;
        tot ^= tmp;

    }
    if(tot == 0) cout << "Bruno" << endl;
    else cout << "Anna" << endl;
    return 0;
}