#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc138/tasks/arc138_c

int main(){
    int n; cin >> n;
    ll ans = 0;
    vector<pii> a(n);
    rep(i, 0, n){
        int A; cin >> A;
        a[i] = {A, i};
    }
    sort(a.begin(), a.end());

    vector<int> b(n);
    rep(i, 0, n){
        if(i < n/2) b[a[i].second] = 1;
        else{
            b[a[i].second] = -1;
            ans += a[i].first;
        }
    }

    vector<int> c(n);
    int x = 0;
    rep(i, 0, n){
        if(i == 0) c[i] = b[i];
        else{
            c[i] = c[i-1]+b[i];
            if(c[x] > c[i]) x = i;
        }
    }

    cout << x << " " << ans << endl;
    return 0;
}