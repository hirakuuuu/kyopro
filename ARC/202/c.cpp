#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
- レピュニット数の GCD の良い性質として， gcd(Rn, Rm) = R_{gcd(n, m)} というのがある
- これを踏まえると，Rn = \prod_{d|n} F_d みたいな形で書けてれば，lcm が登場する約数全部について F_i をかけたものになる．

*/

int main(){
    vector<mint> r(250005);
    r[0] = r[1] = 1;
    rep(i, 2, 250005){
        r[i] = r[i-1]*10+1;
    }

    vector<mint> f(250005);
    rep(i, 2, 250005){
        f[i] = r[i];
        for(int j = 2; j*j <= i; j++){
            if(i%j == 0){
                f[i] /= f[j];
                if(i/j != j) f[i] /= f[i/j];
            }
        }
    }

    int n; cin >> n;
    vector<bool> seen(250005);
    mint ans = 1;
    seen[1] = true;
    rep(i, 0, n){
        int a; cin >> a;
        for(int j = 1; j*j <= a; j++){
            if(a%j == 0){
                if(!seen[j]){
                    ans *= f[j];
                    seen[j] = true;
                }
                if(j != a/j && !seen[a/j]){
                    ans *= f[a/j];
                    seen[a/j] = true;
                }
            }
        }
        cout << ans.val() << endl;
    }


    return 0;
}