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
        int n; cin >> n;
        vector<int> p(1<<n);
        rep(i, 0, 1<<n){
            cin >> p[i];
        }


        rrep(b, n, 1){
            int B = (1<<b);
            rep(a, 0, IINF){
                if((a+1)*B > 1<<n) break;
                int l = a*B, r = (a+1)*B;
                // [l, r) を反転して辞書順で早くなるなら反転する
                // 前半と後半の数でより小さい数が含まれる方を前にしたい
                int mi_l = IINF, mi_r = IINF;
                rep(i, l, (l+r+1)/2) chmin(mi_l, p[i]);
                rep(i, (l+r+1)/2, r) chmin(mi_r, p[i]);

                if(mi_l > mi_r){
                    for(int m = l; m < r+l-1-m; m++){
                        swap(p[m], p[r+l-1-m]);
                    }
                }
            }
        }
        rep(i, 0, 1<<n){
            cout << p[i] << ' ';
        }
        cout << endl;

    }
    
    return 0;
}