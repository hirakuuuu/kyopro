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


int main(){
    int n, a, b, c; cin >> n >> a >> b >> c;

    vector<mint> fact(550005), inv_fact(550005);
    fact[0] = inv_fact[0] = 1;
    fact[1] = inv_fact[1] = 1;
    rep(i, 2, 550005){
        fact[i] = fact[i-1]*i;
        inv_fact[i] = inv_fact[i-1]/i;
    }

    {
        vector<mint> fa(n+1), fb(n+1), fc(n+1);
        for(int i = 0; i <= n; i += a) fa[i] = 1;
        for(int i = 0; i <= n; i += b) fb[i] = 1;
        for(int i = 0; i <= n; i += c) fc[i] = 1;
        vector<mint> F1 = convolution(fa, fb);
        vector<mint> F2 = convolution(F1, fc);
        cout << F2[n].val() << endl;
    }
    {
        vector<mint> fa(n+1), fb(n+1), fc(n+1);
        for(int i = 0; i <= n; i += a) fa[i] = inv_fact[i];
        for(int i = 0; i <= n; i += b) fb[i] = inv_fact[i];
        for(int i = 0; i <= n; i += c) fc[i] = inv_fact[i];
        vector<mint> F1 = convolution(fa, fb);
        vector<mint> F2 = convolution(F1, fc);
        cout << (F2[n]*fact[n]).val() << endl;
    }
    
    return 0;
}