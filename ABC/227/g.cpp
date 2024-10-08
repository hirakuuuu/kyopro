#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
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
    ll n, k; cin >> n >> k;
    mint ans = 1;
    vector<ll> cnt(1000005);

    // 10^6 以下の素数をカウントする
    rep(i, 2, 1000001){
        if(erat[i] != 0) continue;
        ll tmp = i;
        while(tmp <= n){
            cnt[i] += (n/tmp)-((n-k)/tmp);
            tmp *= i;
        }
    }
    rep(i, 2, k+1){
        vector<pair<int, int>> pf = prime_factorization(i);
        for(auto [p, e]: pf) cnt[p] -= e;
    }
    rep(i, 2, 1000001) ans *= cnt[i]+1;

    // 10^6 より大きい素数
    vector<ll> a(k);
    rep(i, 0, k) a[i] = n-k+1+i;
    rep(i, 2, 1000001){
        if(erat[i] != 0) continue;
        // n-k+1 以上の i の倍数
        ll j = (i-(n-k+1)%i)%i;
        for(; j < k; j += i){
            while(a[j]%i == 0) a[j] /= i;
        }
    }
    rep(i, 0, k){
        if(a[i] > 1000000) ans *= 2;
    }
    cout << ans.val() << endl;
    return 0;
}