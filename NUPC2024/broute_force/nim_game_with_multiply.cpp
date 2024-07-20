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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
n = 1 は解析済み

n = 2
$n = 2$ の場合（総当たりからの予想です、証明は後で考えます...）
- $d= 1$ のとき、 $a = \lbrace 1, 1 \rbrace$ なら後手必勝、そうでなければ先手必勝
- $d= 2$ のとき、 $a = \lbrace 1, 2 \rbrace,  \lbrace 2, 2 \rbrace$ なら後手必勝、そうでなければ先手必勝
- $d= 3$ のとき、 $a = \lbrace 1, 3 \rbrace,  \lbrace 2, 3 \rbrace$ なら後手必勝、そうでなければ先手必勝
- $d\ge 4$ のとき、 $a = \lbrace 1, d \rbrace,  \lbrace 2, d \rbrace, \lbrace l, m \rbrace (3\le l\le d-1, \max{(d+3, l+d-3)}\le m\le 2d-1)$ なら後手必勝、そうでなければ先手必勝

n = 3
- 
*/



// verify: https://atcoder.jp/contests/abc362/tasks/abc362_g
int main(){
    const int n = 2;
    map<pair<vector<int>, int>, int> memo;
    vector<int> a;
    // 探索関数
    // 1なら先手必勝, 0 なら後手必勝
    auto f = [&](auto self, int d) -> int {
        if(memo.find({a, d}) != memo.end()) return memo[{a, d}];

        rep(i, 0, n){
            int ai = a[i];
            for(int tmp = d; tmp <= ai; tmp += d){
                // d の倍数を取り除く
                a[i] = ai-tmp;

                // 選べる d を選ぶ（max a まで）
                int mx = 0;
                rep(j, 0, n) chmax(mx, a[j]);
                if(mx == 0){
                    a[i] = ai;
                    return memo[{a, d}] = 1;
                }
                rep(j, 1, mx+1){
                    if(self(self, j) == 0){
                        a[i] = ai;
                        return memo[{a, d}] = 1;
                    }
                }
            }
            a[i] = ai;
        }
        return memo[{a, d}] = 0;
    };

    rep(d, 1, 21){
        rep(a1, 1, 51) rep(a2, max(a1, d), 51){
            
            a = {a1, a2};
            // max a >= d の確認
            bool ok = false;
            rep(i, 0, n){
                if(d <= a[i]) ok = true;
            }
            assert(ok);


            if(f(f, d) == 0){
                cout << "d = " << right << setw(2) << d << ", a = {" << right << setw(2) << a[0] << ", " << right << setw(2) << a[1] <<  "}." <<endl;
            }
        }
    }

    return 0;
}