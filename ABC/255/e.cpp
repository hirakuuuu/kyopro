#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc255/tasks/abc255_e

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> s(n-1), x(m), rs(n-1);
    rep(i, 0, n-1){
        cin >> s[i];
        rs[i] = s[i];
        if(i > 0) rs[i] -= rs[i-1];
    }
    rep(i, 0, m) cin >> x[i];
    map<ll, ll> cnt;
    rep(i, 0, m) cnt[x[i]]++;
    ll ans = 0, max_a = 0;
    rep(i, 0, n-1){
        int pm = 1;
        if(i%2) pm = -pm;
        rep(j, 0, m){
            cnt[pm*(rs[i]-x[j])]++;
            if(ans < cnt[pm*(rs[i]-x[j])]){
                ans = cnt[pm*(rs[i]-x[j])];
                max_a = pm*(rs[i]-x[j]);
            }
        }
    }

    cout << ans << endl;


    
    return 0;
}