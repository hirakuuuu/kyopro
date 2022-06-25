#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc257/tasks/abc257_b

int main(){
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(k);

    rep(i, 0, k) cin >> a[i];
    while(q--){
        int l; cin >> l;
        if(a[l-1] == n) continue;
        if(l-1 == k-1) a[l-1]++;
        else if(a[l-1]+1 != a[l]) a[l-1]++; 
    }
    rep(i, 0, k) cout << a[i] << " ";
    cout << endl;
    
    return 0;
}