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
// https://atcoder.jp/contests/abc284/tasks/abc284_b

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = 0;
        rep(i, 0, n){
            int a; cin >> a;
            if(a%2) ans++;
        }
        cout << ans << endl;
    }

    
    return 0;
}