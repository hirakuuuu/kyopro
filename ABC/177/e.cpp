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
constexpr ll INF = 9e18;

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
    vector<int> a(n);
    vector<vector<pair<ll, ll>>> pf(n);
    rep(i, 0, n){
        cin >> a[i];
        pf[i] = prime_factorization(a[i]);
    }

    int g = a[0];
    rep(i, 1, n) g = gcd(g, a[i]);

    vector<int> cnt(1000005);
    bool pc = true;
    rrep(i, n-1, 0){
        // bool pc = true;
        for(auto [p, e]: pf[i]){
            if(cnt[p] >= 1) pc = false;
            cnt[p] = 1;
        }
    }
    if(pc){
        cout << "pairwise coprime" << endl;
    }else if(g == 1){
        cout << "setwise coprime" << endl;
    }else{
        cout << "not coprime" << endl;
    }


    
    return 0;
}