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
// https://atcoder.jp/contests/abc309/tasks/abc309_b

int main(){
    int n; cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
        }
    }

    vector<vector<char>> b = a;
    b[0][0] = a[1][0];
    rep(i, 1, n){
        b[0][i] = a[0][i-1];
    }
    rep(i, 1, n){
        b[i][n-1] = a[i-1][n-1];
    }
    rrep(i, n-2, 0){
        b[n-1][i] = a[n-1][i+1];
    }
    rrep(i, n-2, 0){
        b[i][0] = a[i+1][0];
    }

    rep(i, 0, n){
        rep(j, 0, n){
            cout << b[i][j];
        }
        cout << endl;
    }

    
    return 0;
}