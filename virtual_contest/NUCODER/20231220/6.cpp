#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    int n, k; cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
            a[i][j] = -a[i][j];
        }
    }

    int ng = 1, ok = -1e9-1;
    while(ng-ok > 1){
        int m = (ok+ng)/2;
        vector<vector<int>> x(n, vector<int>(n));
        rep(i, 0, n){
            rep(j, 0, n){
                if(a[i][j] < m) x[i][j] = 1;
                else x[i][j] = 0;
            }
        }

        vector<vector<int>> acc(n+1, vector<int>(n+1));
        rep(i, 0, n){
            rep(j, 0, n){
                acc[i+1][j+1] = acc[i][j+1]+acc[i+1][j]-acc[i][j]+x[i][j];
            }
        }

        bool f = false;
        rep(i, k, n+1){
            rep(j, k, n+1){
                if(acc[i][j]-acc[i-k][j]-acc[i][j-k]+acc[i-k][j-k] < k*k/2+1) f = true;
            }
        }

        if(f) ok = m;
        else ng = m;
    }
    
    cout << -ok << endl;
    return 0;
}