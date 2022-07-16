#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tasks/arc144_b

int main(){
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> A(n);
    rep(i, 0, n){
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    ll l = A[0], r = 1000000007;

    while(r-l > 1){
        ll m = (l+r)/2;
        ll k = 0;
        rep(i, 0, n){
            if(A[i] <= m){
                k += (m-A[i])/a + ((m-A[i])%a > 0);
            }else{
                k -= (A[i]-m)/b;
            }
        }
        if(k <= 0) l = m;
        else r = m;
    }

    cout << l << endl;
    
    return 0;
}