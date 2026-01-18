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

    int k; cin >> k;
    mint ans = 0;
    for(int a = 2; a <= k; a++){
        for(int b = 2; b <= k; b++){
            int c = k-a-b;
            if(c < 2 || k < c) continue;
            ans += mint(a-1)*(b-1)*(c-1)*(k-max({a, b, c}));
        }
    }
    cout << ans.val() << endl;

    return 0;
}