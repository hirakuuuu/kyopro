#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc277/tasks/abc277_d

int main(){
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<pll> b(n);
    vector<pll> c(2*n);
    ll sum_a = 0;
    rep(i, 0, n){
        cin >> a[i];
        sum_a += a[i];
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());

    rep(i, 0, 2*n){
        c[i] = b[i%n];
    }
    ll max_a = 0;
    rep(i, 0, n){
        ll sum_c = a[c[i].second];
        int j = i+1;
        while(j < i+n and (c[j-1].first == c[j].first or (c[j-1].first+1)%m == c[j].first)){
            sum_c += a[c[j].second];
            j++;
        }
        i = j-1;
        max_a = max(max_a, sum_c);
    }

    cout << sum_a-max_a << endl;



    
    return 0;
}