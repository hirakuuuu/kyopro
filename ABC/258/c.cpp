#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc258/tasks/abc258_c

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    ll X = 0;
    while(q--){
        ll t, x; cin >> t >> x;
        if(t == 1){
            X += n-x;
        }else{
            cout << s[(x-1+X)%n] << endl;

        }
    }
    
    return 0;
}