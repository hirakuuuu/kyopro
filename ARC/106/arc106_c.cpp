#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc106/tasks/arc106_c

/*
高橋くんの方が多い・・・でかい区間が一つあって、そこに複数の区間が含まれている場合
N-1個は確実にとれるから、青木にN-1-M個取らせれば良い
青木くんの方が多い・・・むり？
*/

int main(){
    int n, m; cin >> n >> m;
    if(n == 1 and m == 0){
        cout << 1 << ' ' << 2 << endl;
        return 0;
    }
    if(m < 0 or m >= n-1){
        cout << -1 << endl;
        return 0;
    }


    vector<int> l(n), r(n);
    int L = 2, R = 3;
    l[0] = 1;
    rep(i, 0, m+1){
        l[i+1] = L;
        r[i+1] = R;
        L = R+1;
        R = L+1;
    }
    r[0] = L;
    L++;
    R = L+1;

    rep(i, m+2, n){
        l[i] = L;
        r[i] = R;
        L = R+1;
        R = L+1;
    }

    rep(i, 0, n){
        cout << l[i] << ' ' << r[i] << endl;
    }




    
    return 0;
}