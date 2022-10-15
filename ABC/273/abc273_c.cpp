#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc273/tasks/abc273_c

int main(){
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    rep(i, 0, n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    vector<int> ans(n);
    rep(i, 0, a.size()){
        ans[i] = cnt[a[a.size()-1-i]];
    }

    rep(i, 0, n){
        cout << ans[i] << "\n";
    }





    
    return 0;
}