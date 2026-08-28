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
    int n; cin >> n;
    if(n%2 == 0){
        cout << n*n << endl;
        rep(i, 0, n){
            rep(j, 0, n){
                cout << 1 << ' ';
            }
            cout << endl;
        }
    }else{
        if(n <= 3){
            cout << -1 << endl;
        }else{
            vector<vector<int>> a(n, vector<int>(n, 1));
            a[0][0] = 2;
            rep(i, 0, n){
                int j = n-i;
                if(inr(0, i, n) && inr(0, j, n)) a[i][j] = 2;
            }

            a[n-1][n-1] = 3;
            rep(i, 0, n){
                int j = n-2-i;
                if(inr(0, i, n) && inr(0, j, n)) a[i][j] = 3;
            }

            swap(a[n-3][0], a[n-3][1]);
            swap(a[n-2][0], a[n-2][1]);
            swap(a[1][n-2], a[1][n-1]);
            swap(a[2][n-2], a[2][n-1]);

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
            assert(ok);
            int sum = 0;
            rep(i, 0, n){
                rep(j, 0, n){
                    sum += a[i][j];
                }
            }
            cout << sum << endl;
            rep(i, 0, n){
                rep(j, 0, n){
                    cout << a[i][j] << ' ';
                }
                cout << endl;
            }
        }
    }

    return 0;
}