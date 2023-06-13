#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc305/tasks/abc305_g

// lxm mxn の掛け算
vector<vector<ll>> matrix_maltiple(vector<vector<ll>> A, vector<vector<ll>> B){
    int l = A.size();
    int m = A[0].size();
    int n = B[0].size();

    vector<vector<ll>> C(l, vector<ll>(n));
    rep(i, 0, l){
        rep(j, 0, m){
            rep(k, 0, n){
                C[i][k] += A[i][j]*B[j][k];
            }
        }
    }
    return C;
}

vector<vector<ll>> matrix_power(vector<vector<ll>> A, ll N){
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n));
    rep(i, 0, n){
        C[i][i] = 1;
    }

    ll tmp = N;
    while(tmp){
        if(tmp&1) C = matrix_maltiple(C, A);
        A = matrix_maltiple(A, A);
        tmp >>= 1;
    }

    return C;
}

int main(){
    
    return 0;
}