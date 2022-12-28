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
// https://atcoder.jp/contests/abc174/tasks/abc174_e

/*めぐる式*/

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    int ng = 0, ok = 1e9+1;
    while(ok-ng > 1){
        int m = (ng+ok)/2;
        int cnt = 0;
        rep(i, 0, n){
            cnt += (a[i]+m-1)/m-1;
        }
        if(cnt <= k) ok = m;
        else ng = m;
    }

    cout << ok << endl;




    
    return 0;
}