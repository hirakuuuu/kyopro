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
// https://atcoder.jp/contests/arc152/tasks/arc152_a

int main(){
    int n, l; cin >> n >> l;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n){
        if(a[n-i-1] == 2){
            if(l-(l-(i+2)+(n-i-1)) >= 2) cout << "Yes" << endl;
            else cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}