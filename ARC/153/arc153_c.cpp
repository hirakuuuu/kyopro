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
// https://atcoder.jp/contests/arc153/tasks/arc153_c

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<ll> b(n+1);
    for(int i = n-1; i >= 0; i--){
        b[i] = b[i+1]+a[i];
    }
    ll sum_b = 0;
    rep(i, 1, n) sum_b += b[i];

    vector<ll> y(n, 1);
    if(b[0] != 0){
        y[0] = -sum_b*abs(b[0])/b[0];
        rep(i, 1, n) y[i] = abs(b[0]);
    }else{
        int p = -1, q = -1;
        rep(i, 0, n){
            if(b[i] == 1) p = i;
            else if(b[i] == -1) q = i;
        }

        if(p == -1 || q == -1){
            cout << "No" << endl;
            return 0;
        }

        if(sum_b > 0) y[q] += sum_b;
        else if(sum_b < 0) y[p] -= sum_b;
    }

    cout << "Yes" << endl;
    ll tmp = 0;
    rep(i, 0, n){
        tmp += y[i];
        cout << tmp << (i == n-1 ? '\n' : ' ');
    }

    return 0;
}