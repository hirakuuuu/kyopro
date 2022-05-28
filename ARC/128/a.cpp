#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc128/tasks/arc128_a

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> ans(n);
    int i = 0;
    while(i < n){
        int j = i;
        while(i < n and a[i] > a[i+1]){
            i++;
        }

        if(i == j){
            i++;
            continue;
        }
        if(a[j] > a[min(i, n-1)]) ans[min(i, n-1)] = ans[j] = 1;
    }

    rep(k, 0, n){
        if(k) cout << ' ';
        cout << ans[k];
    }
    cout << endl;
    
    return 0;
}