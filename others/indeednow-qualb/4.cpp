#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/indeednow-qualb/tasks/indeednow_2015_qualb_4

int main(){
    ll n, c; cin >> n >> c;
    vector<vector<ll>> b(c+1);
    rep(i, 1, c+1) b[i].push_back(0);
    rep(i, 0, n){
        ll a; cin >> a;
        b[a].push_back(i+1);
    }
    rep(i, 1, c+1) b[i].push_back(n+1);

    ll total = n*(n+1)/2;

    rep(i, 1, c+1){
        total = n*(n+1)/2;
        rep(j, 0, b[i].size()-1){
            ll d = b[i][j+1]-b[i][j]-1;
            total -= d*(d+1)/2;
        }
        cout << total << endl;
    }
    
    return 0;
}