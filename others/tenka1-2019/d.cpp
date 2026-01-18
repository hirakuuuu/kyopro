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
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    rep(i, 0, n){
        cin >> a[i];
        sum += a[i];
    }

    vector<mint> f1(1);
    f1[0] = 1;
    vector<mint> f2(1);
    f2[0] = 1;
    rep(i, 0, n){
        vector<mint> g1(a[i]+1);
        g1[0] = 1;
        g1[a[i]] = 1;
        f1 = convolution(f1, g1);
        
        vector<mint> g2(a[i]+1);
        g2[0] = 2;
        g2[a[i]] = 1;
        f2 = convolution(f2, g2);
    }

    mint ans = mint(3).pow(n)-mint(2).pow(n)*3+3;
    rep(i, (sum+1)/2, sum){
        ans -= (f2[i]-f1[i]*2)*3;
    }
    cout << ans.val() << endl;

    
    return 0;
}