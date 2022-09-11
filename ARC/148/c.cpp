#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc148/tasks/arc148_c

int main(){
    int n, q; cin >> n >> q;
    vector<int> p(n), cnt_c(n);
    rep(i, 1, n){
        cin >> p[i];
        p[i]--;
        cnt_c[p[i]]++;
    }

    while(q--){
        int m; cin >> m;
        vector<int> v(m);
        map<int, bool> ura;
        rep(i, 0, m){
            cin >> v[i];
            v[i]--;
            ura[v[i]] = true;
        }

        int ans = 0;

        rep(i, 0, m){
            ans += 1+cnt_c[v[i]];
            if(v[i] != 0 and ura[p[v[i]]]) ans -= 2;
        }
        cout << ans << endl;
    }
    return 0;
}