#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc275/tasks/abc275_a

int main(){
    int n; cin >> n;
    int ans = 0, id = 0;
    rep(i, 0, n){
        int h; cin >> h;
        if(ans < h){
            id = i+1;
            ans = h;
        }
    }
    cout << id << endl;
    
    return 0;
}