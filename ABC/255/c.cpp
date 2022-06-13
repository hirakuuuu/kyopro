#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc255/tasks/abc255_c

int main(){
    ll x, a, d, n; cin >> x >> a >> d >> n;
    ll b = a+d*(n-1);
    if(d < 0) swap(a, b);
    if(x <= a){
        cout << a-x << endl;
    }else if(b <= x){
        cout << x-b << endl;
    }else{
        cout << min(abs(x-a)%d, abs(b-x)%d) << endl;
    }


    
    return 0;
}