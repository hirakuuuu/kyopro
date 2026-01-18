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

int main(){
    int t; cin >> t;
    while(t--){
        ll n, l, r, k; cin >> n >> l >> r >> k;
        if(n%2 == 1){
            cout << l << endl;
        }else{
            if(n == 2){
                cout << -1 << endl;
                continue;
            }
            // l, r の2進数の桁数が一致してると無理
            int len_l = 0, len_r = 0;
            {
                ll num = l;
                while(num){
                    len_l++;
                    num >>= 1;
                }
                num = r;
                while(num){
                    len_r++;
                    num >>= 1;
                }
            }
            if(len_l == len_r){
                cout << -1 << endl;
                continue;
            }


            if(k <= n-2){
                cout << l << endl;
            }else{
                cout << (1LL<<(len_l)) << endl;
            }
        }
    }
    return 0;
}