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

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 素数列挙
vector<int> prime_enumerate(int N) {
  vector<bool> is_prime(N + 1, true);
  vector<int> primes;
  if (N < 2) return primes;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) is_prime[j] = false;
    }
  }
  for (int i = 2; i <= N; ++i) {
    if (is_prime[i]) primes.push_back(i);
  }
  return primes;
}


int main(){
    vector<int> primes = prime_enumerate(10000005);

    ll l, r; cin >> l >> r;
    l++; // a_l の寄与を考えると [l+1, r]の区間の素数べきを数えればよい
    ll ans = 1;
    vector<bool> seen(r-l+1);

    // 区間篩
    // [l, r]の数字をすべて素因数分解する
    // 計算時間: O(M\log{\log{M}}), M = max(R-L, \sqrt(R));
    for(int p: primes){
        for(ll x = l+(p-l%p)%p; x <= r; x += p){
            if(seen[x-l]) continue;
            seen[x-l] = true;
            ll y = x;
            while(y%p == 0) y /= p;
            if(y == 1) ans++;
        }
    }
    for(auto s: seen) if(!s) ans++;
    cout << ans << endl;

    
    return 0;
}