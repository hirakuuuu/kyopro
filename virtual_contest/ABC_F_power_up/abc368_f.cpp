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
// using mint2 = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


// 0ならば素数, 0でないなら最小の素因数
const int MAX_N = 100005;
vector<int> min_prime(MAX_N+1);
void eratosthenes(){
    rep(i, 2LL, (ll)sqrt(MAX_N)+1){
        if(min_prime[i] == 0){
            for(ll j = i*i; j <= MAX_N; j += i){
                if(min_prime[j] == 0) min_prime[j] = i;
            }
        }
    }
}

// 素因数分解 O(log{x})
vector<pair<int, int>> prime_factorization(ll x){
    vector<pair<int, int>> res;
    while(min_prime[x] != 0){
        ll p = min_prime[x];
        res.push_back({p, 0});
        while(x%p == 0){
            x /= p;
            res.back().second++;
        }
    }
    if(x != 1) res.push_back({x, 1});
    return res;
};

int main(){
    eratosthenes();
    int n; cin >> n;
    vector<int> nim(n);
    int g = 0;
    rep(i, 0, n){
        int a; cin >> a;
        for(auto [p, e]: prime_factorization(a)){
            nim[i] += e;
        }
        g^= nim[i];
    }
    if(g == 0) cout << "Bruno" << endl;
    else cout << "Anna" << endl;


    
    return 0;
}