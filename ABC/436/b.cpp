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
    vector<vector<int>> a(n, vector<int>(n));
    a[0][(n-1)/2] = 1;
    int k = 1;
    int r = 0, c = (n-1)/2;
    rep(i, 0, n*n-1){
        if(!a[(r-1+n)%n][(c+1)%n]){
            a[(r-1+n)%n][(c+1)%n] = k+1;
            r = (r-1+n)%n;
            c = (c+1)%n;
        }else{
            a[(r+1)%n][c] = k+1;
            r = (r+1)%n;
        }
        k++;
    }
    rep(i, 0, n){
        rep(j, 0, n){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}