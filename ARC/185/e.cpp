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
- 動的計画法により，a[i] の寄与を考えるだけでよくなる
- トーシェント関数を使うと，約数の部分だけで考えられるように変形できる
*/

// オイラーのφ関数
ll euler_phi(ll n){
    ll ret = n;
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            ret -= ret/i;
            while(n%i == 0) n /= i;
        }
    }
    if(n > 1) ret -= ret/n;
    return ret;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<int>> yakusu(100005);
    rep(i, 1, 100005){
        for(int j = 1; j*j <= i; j++){
            if(i%j == 0){
                yakusu[i].push_back(j);
                if(i/j != j){
                    yakusu[i].push_back(i/j);
                }
            }
        }
        sort(yakusu[i].begin(), yakusu[i].end());
    }
    vector<int> phi(100005);
    rep(i, 1, 100005) phi[i] = euler_phi(i);
    
    vector<mint> s(100005);
    mint ans = 0;
    rep(i, 0, n){
        ans *= 2;
        for(auto yy: yakusu[a[i]]){
            ans += phi[yy]*s[yy];
        }
        mint tmp = mint(2).pow(i);
        for(auto yy: yakusu[a[i]]){
            s[yy] += tmp;
        }   
        cout << ans.val() << endl;
    }
    return 0;
}