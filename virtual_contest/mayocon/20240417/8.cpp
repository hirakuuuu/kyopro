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
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const int vmax = 250005;
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

mint homogeneous(int n, int k){
    return choose(n+k-1, k);
}

/*
dp[i][j] := 上位i桁確定させて、ｎより小さいことが確定している数で、使っている数字がｊ種類
遷移はすでに使っている数字から選ぶか、そうでない数字から選ぶかで2通りにまとめることができる
 dp[i+1][j] += dp[i][j]*j
 dp[i+1][j+1] += dp[i][j]*(16-j)

また、ｎと等しかった数字からの遷移とそれまでに０しか現れていなかった数字を新たに追加する必要がある
*/

int main(){
    string s;
    int k; cin >> s >> k;
    int n = (int)s.size();
    map<char, int> num;
    rep(i, 0, 10) num['0'+i] = i;
    rep(i, 0, 6) num['A'+i] = 10+i;
    initfact();
    vector<vector<mint>> dp(n, vector<mint>(18));
    dp[0][1] = num[s[0]]-1;
    set<int> c;
    c.insert(num[s[0]]);
    rep(i, 1, n){
        int tmp = num[s[i]];
        rep(j, 0, k+1){
            dp[i][j] += dp[i-1][j]*j;
            dp[i][j+1] += dp[i-1][j]*(16-j);
        }
        // cout << c.size() << endl;
        rep(j, 0, tmp){
            if(c.find(j) != c.end()) dp[i][c.size()] += 1;
            else dp[i][c.size()+1] += 1;
        }
        dp[i][1] += 15;
        c.insert(num[s[i]]);
        // rep(j, 0, k+1) cout << dp[i][j].val() << ' ';
        // cout << endl;
    }
    dp[n-1][c.size()]++;
    cout << dp[n-1][k].val() << endl;
    return 0;
}