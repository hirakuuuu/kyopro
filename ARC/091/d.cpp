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
grundy 数 (x, k)
- 1 <= x < k: 0

(1, 0 ... の繰り返し)

(k <= x < 2k)
(1, 0 ... の繰り返し)
- x = k: 1
- x = k+1: 0
- x = k+2: 1
...
- x = k+i: (i が 偶数 ? 1: 0)
...
- x = 2k-1: (k が奇数 ? 1 : 0)

(2k <= x < 3k)
k を 2 で割った余りが 0: 2, 1, 0, ... の繰り返し
k を 2 で割った余りが 1: 2, 0, 1, ... の繰り返し

(3k <= x < 4k)
k を 3 で割った余りが 0: (3, 2, 1, 0) or (3, 2, 0, 1) ... の繰り返し
k を 3 で割った余りが 1: (3, 1, 0, 2) or (3, 0, 1, 2) ... の繰り返し
k を 3 で割った余りが 2: (3, 0, 2, 1) or (3, 1, 2, 0) ... の繰り返し

- x = 2k: 2
- x = 2k+1: 0
- x = 2k+2: 1

()
- x = 3k: 3
- x = 3k+1: 
*/



int main(){
    // map<pair<int, int>, int> grundy;
    // auto calc = [&](auto self, int x, int k) -> int {
    //     if(grundy.count({x, k})) return grundy[{x, k}];

    //     set<int> s;
    //     rep(i, 1, (x/k)+1){
    //         s.insert(self(self, x-i, k));
    //     }

    //     int g = 0;
    //     while(true){
    //         if(s.count(g)){
    //             g++;
    //             continue;
    //         }
    //         break;
    //     }
    //     return grundy[{x, k}] = g;
    // };

    // rep(k, 1, 11){
    //     cout << "#####################################" << endl; 
    //     rep(x, 1, 101){
    //         cout << "k=" << k << ", x=" << x << ": " << calc(calc, x, k) << ", " << calc(calc, x-(x/k+1), k) << endl;
    //     }
    // }

    int n; cin >> n;
    int g = 0;
    rep(i, 0, n){
        int x, k; cin >> x >> k;
        while(x >= k && x%k != 0){
            x -= x/k+1;
        }
        if(x >= k) g ^= (x/k);
    }
    if(g) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;


    return 0;
}