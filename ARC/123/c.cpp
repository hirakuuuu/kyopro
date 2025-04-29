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

/*
N = q*10+r とすると，N が k 個以下の良い数で書けるのは，以下の条件を満たすとき
- k <= r  <= 3k
- q が k 個以下の良い数で書ける

これを再帰的に計算すればよい
また，どんな N でも 5 個以下の良い数で書ける
*/

int main(){
    unordered_map<ll, int> memo;
    auto solve = [&](auto self, ll n) -> int {
        if(n == 0) return 0;
        if(memo.count(n)) return memo[n];

        int res = -1;
        ll q = n/10, r = n%10;
        if((1 <= r && r <= 3) && self(self, q) <= 1) res = 1;
        else if((2 <= r && r <= 6) && self(self, q) <= 2) res = 2;
        else if((3 <= r && r <= 9) && self(self, q) <= 3) res = 3;
        else if((4 <= r && r <= 9) && self(self, q) <= 4) res = 4;
        else if((0 <= r && r <= 2) && self(self, q-1) <= 4) res = 4;
        else res = 5;

        return memo[n] = res;
    };
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << solve(solve, n) << endl;
    }
    return 0;
}