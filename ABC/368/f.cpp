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
const int MAX_N = 1000005;
vector<int> erat(MAX_N+1);
void init_e(){
    rep(i, 2LL, (ll)sqrt(MAX_N)+1){
        if(erat[i] == 0){
            for(ll j = i*i; j <= MAX_N; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

// 素因数分解 O(log{x})
vector<pair<int, int>> prime_factorization(ll x){
    vector<pair<int, int>> res;
    while(erat[x] != 0){
        ll p = erat[x];
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
    init_e();
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> b(n);
    int g = 0;
    rep(i, 0, n){
        vector<pair<int, int>> pf = prime_factorization(a[i]);
        for(auto [_, exp]: pf){
            b[i] += exp;
        }
        g ^= b[i];
    }
    if(g) cout << "Anna" << endl;
    else cout << "Bruno" << endl;


    
    return 0;
}