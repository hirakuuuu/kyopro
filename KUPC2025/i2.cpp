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
    int n =5;
    rep(i, 1, 1<<(n*n)){
        vector<vector<int>> a(n, vector<int>(n));
        rep(j, 0, n){
            rep(k, 0, n){
                if(i>>(j*n+k)&1){
                    a[j][k] = 2;
                }else{
                    a[j][k] = 1;
                }
            }
        }

        bool ok = true;
        rep(j, 0, n){
            int sum = 0;
            rep(k, 0, n) sum ^= a[j][k];
            if(sum != 0) ok = false;
        }
        rep(j, 0, n){
            int sum = 0;
            rep(k, 0, n) sum ^= a[k][j];
            if(sum != 0) ok = false;
        }
        {
            int sum = 0;
            rep(j, 0, n) sum ^= a[j][j];
            if(sum != 0) ok = false;
        }

        {
            int sum = 0;
            rep(j, 0, n) sum *= a[n-1-j][j];
            if(sum != 0) ok = false;
        }

        if(ok){
            rep(j, 0, n){
                rep(k, 0, n){
                    cout << a[j][k] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    return 0;
}