#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc279/tasks/abc279_e

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m);
    rep(i, 0, m){
        cin >> a[i];
        a[i]--;
    }

    vector<int> b(n);
    rep(i, 0, n) b[i] = i+1;
    vector<int> c = b;
    rep(i, 0, m){
        swap(c[a[i]], c[a[i]+1]);
    }
    vector<int> ci(n+1);
    rep(i, 0, n){
        ci[c[i]] = i+1;
    }

    rep(i, 0, m){
        int l = b[a[i]], r = b[a[i]+1];
        if(l == 1) cout << ci[r] << endl;
        else if(r == 1) cout << ci[l] << endl;
        else cout << ci[1] << endl;
        swap(b[a[i]], b[a[i]+1]);
    }
    
    return 0;
}