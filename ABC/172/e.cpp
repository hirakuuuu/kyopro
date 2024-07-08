#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


const int vmax = 1000005;
mint fact[vmax],finv[vmax],invs[vmax];
void initfact(){
	fact[0]=1;
	rep(i,1,vmax){
		fact[i]=fact[i-1]*i;
	}
	finv[vmax-1]=fact[vmax-1].inv();
	for(int i=vmax-2;i>=0;i--){
		finv[i]=finv[i+1]*(i+1);
	}
	for(int i=vmax-1;i>=1;i--){
		invs[i]=finv[i]*fact[i-1];
	}
}
mint perm(int n, int k){
	return n-k >= 0?fact[n]*finv[n-k]:0;
}
mint choose(int n,int k){
	return n-k >= 0?fact[n]*finv[n-k]*finv[k]:0;
}
mint binom(int a,int b){
	return 0<=a&&0<=b?fact[a+b]*finv[a]*finv[b]:0;
}
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}


int main(){
    initfact();
    int n, m; cin >> n >> m;
    mint ans = perm(m, n)*perm(m, n);

    rep(i, 1, n+1){
        if(i%2 == 1) ans -= perm(m, n)*choose(n, i)*perm(m-i, n-i);
        else ans += perm(m, n)*choose(n, i)*perm(m-i, n-i);
    }
    cout << ans.val() << endl;


    
    
    return 0;
}