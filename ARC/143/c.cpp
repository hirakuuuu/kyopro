#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc143/tasks/arc143_c

int main(){
    ll a, b, c; cin >> a >> b >> c;
    vector<ll> d = {a, b, c};
    sort(d.begin(), d.end());
    d[1] -= d[0];
    d[2] -= d[1];

    if(d[2]%3 == 0){
        cout << d[0]+d[1]+d[2]/3 << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}