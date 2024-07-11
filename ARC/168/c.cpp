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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


const int vmax = 350005;
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
mint choose(int n,int k){
	return n-k >= 0?fact[n]*finv[n-k]*finv[k]:0;
}
mint binom(int a,int b){
	return 0<=a&&0<=b?fact[a+b]*finv[a]*finv[b]:0;
}
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}

/*
cnt[s[i]][t[i]] の個数を数えると最小の操作回数が分かる.

*/


int main(){
    initfact();
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> cnt(3);
    rep(i, 0, n){
        cnt[s[i]-'A']++;
    }
    auto three_comb = [&](int a, int b, int c) -> mint {
        if(a < 0 || b < 0 || c < 0) return mint(0);
        return fact[a+b+c]*finv[a]*finv[b]*finv[c];
    };
    mint ans = 0;
    for(int i = 0; i <= k; i++){
        for(int j = 0; i+j <= k; j++){
            for(int l = 0; i+j+l <= k; l++){
                int z = (k-(i+j+l))/2;
                for(int d = -z; d <= z; d++){
                    int v = abs(d);
                    int ab = i+(v >= 0 ? v : 0);
                    int ba = i+(v <= 0 ? v : 0);
                    int bc = j+(v >= 0 ? v : 0);
                    int cb = j+(v <= 0 ? v : 0);
                    int ca = l+(v >= 0 ? v : 0);
                    int ac = l+(v <= 0 ? v : 0);
                    int aa = cnt[0]-ab-ac;
                    int bb = cnt[1]-bc-ba;
                    int cc = cnt[2]-ca-cb;

                    ans += three_comb(aa, ab, ac)*three_comb(ba, bb, bc)*three_comb(ca, cb, cc);
                }
            }
        }
    }
    cout << ans.val() << endl;


    
    return 0;
}