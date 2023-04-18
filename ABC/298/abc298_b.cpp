#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc298/tasks/abc298_b

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> b(n, vector<int>(n));
    rep(i, 0, n){
        rep(j, 0, n) cin >> a[i][j];
    }    
    rep(i, 0, n){
        rep(j, 0, n) cin >> b[i][j];
    }
    vector<int> f(4, true);
    rep(i, 0, n){
        rep(j, 0, n){
            if(a[i][j] == 1 and b[i][j] == 0) f[0] = false;
            if(a[j][n-1-i] == 1 and b[i][j] == 0) f[1] = false;
            if(a[n-1-i][n-1-j] == 1 and b[i][j] == 0) f[2] = false;
            if(a[n-1-j][i] == 1 and b[i][j] == 0) f[3] = false;
        }
    }

    rep(i, 0, 4){
        if(f[i]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;


    return 0;
}