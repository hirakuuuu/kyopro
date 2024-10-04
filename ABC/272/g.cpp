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

/*
過半数取る → 偶数個ならどこかで隣り合うところが必ず選ばれる, 奇数個なら1個飛ばしの場合だけ例外
隣接項を N 通りに対して, その差の約数だけを試せばよい
また、約数ではなく３以上の素数か４について試すだけでOK

決定的ではないが, 適当に２つ選んでも最終的な組に含まれる可能性は 1/4 以上あるので、
２項を乱択で選んで、その素因数について過半数を達成できるかを調べるだけでも５０回程度繰り返せば十分な確率で通る
https://atcoder.jp/contests/abc272/submissions/35483970
*/

// 素因数分解
// {素数、指数}で格納
vector<pair<ll, ll>> prime_factorization(ll n){
    vector<pair<ll, ll>> primes;
    for (ll p = 2; p*p <= n; p++){
        if(n%p != 0) continue;

        ll cnt = 0;
        while(n%p == 0){
            n /= p;
            cnt++;
        }
        primes.push_back({p, cnt});
    }
    if(n != 1) primes.push_back({n, 1});
    return primes;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    // 隣り合う２項について調べる
    rep(i, 0, n){
        int d = abs(a[(i+1)%n]-a[i]);
        if(d <= 2) continue;
        vector<pair<ll, ll>> pf = prime_factorization(d);
        for(auto [p, x]: pf){
            if(p == 2){
                if(x >= 2) p = 4;
                else continue;
            }

            int cnt = 0, y = a[i]%p;
            rep(j, 0, n){
                if(a[j]%p == y) cnt++;
            }
            if(cnt*2 > n){
                cout << p << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    
    return 0;
}