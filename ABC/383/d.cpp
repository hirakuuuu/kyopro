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
const int MAX_N = 4000005;
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

int main(){
    eratosthenes();
    ll n; cin >> n;
    vector<ll> p;
    p.push_back(1LL);
    rep(i, 2, MAX_N){
        if(min_prime[i] == 0) p.push_back(i);
    }

    ll ans = 0;

    // p^8
    rep(i, 1, (int)p.size()){
        ll tmp = 1;
        rep(_, 0, 8) tmp *= p[i];
        if(tmp <= n) ans++;
        else break;
    }
    // p^2q^2
    rep(i, 2, (int)p.size()){
        ll q = p[i];
        int ok = 0, ng = i;
        while(ng-ok > 1){
            int mid = (ok+ng)/2;
            if(p[mid]*p[mid] <= n/(q*q)) ok = mid;
            else ng = mid;
        }
        ans += ok;
    }
    cout << ans << endl;


    
    return 0;
}