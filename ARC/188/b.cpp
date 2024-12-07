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
最初に 0 を塗るとすると、0, 2k, -2k, 4k, -4k, ... と塗られていく
つまり、0 から gcd(n, 2k) 個ごとに塗られてかつ、両者から見て対称な状態になっている

塗られた点の奇数 かつ 全体が偶数のとき、bob が自分の対象軸上の点のどちらかを塗って続けられる。
偶数だったら、alice の手番だが、すでに対象軸上の点はすべて塗られているので、そこで操作は打ち切り。

以上から
- gcd(n, 2k) = 1 なら OK
- gcd(n, 2k) = 2 かつ n/2 = 1 なら OK
- そうでなければ NG 

*/

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        if(gcd(n, 2*k) == 1) cout << "Yes" << endl;
        else if(gcd(n, 2*k) == 2 && (n/2)%2 == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}