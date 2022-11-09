#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/donuts-2015/tasks/donuts_2015_3

int main(){
    int n; cin >> n;
    vector<int> h(n);
    rep(i, 0, n) cin >> h[i];

    vector<int> ans(n);
    vector<int> lis(n+1);
    int l = 0;
    rep(i, 1, n){
        int pos = lower_bound(lis.begin(), lis.begin()+l, -h[i-1])-lis.begin();
        lis[pos] = -h[i-1];
        ans[i] = pos+1;
        if(pos == l){
            l++;
        }else{
            l = pos+1;
        }
    }

    rep(i, 0, n){
        cout << ans[i] << '\n';
    }

    
    return 0;
}