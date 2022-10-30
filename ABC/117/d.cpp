#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc117/tasks/abc117_d

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(40);
    rep(i, 0, n){
        cin >> a[i];
        ll A = a[i], j = 0;
        while(A > 0){
            b[j] += A%2;
            A /= 2;
            j++;
        }
    }

    ll ans = 0;
    rep(i, 0, 40){
        if(n-b[39-i] > n/2){
            if(ans+(1LL<<(39-i)) <= k) ans += 1LL<<(39-i);
        }
    }
    ll sum = 0;
    rep(i, 0, n) sum += a[i]^ans;
    cout << sum << endl;


    
    return 0;
}