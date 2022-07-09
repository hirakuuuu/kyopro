#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc258/tasks/abc258_e

int main(){
    ll n, q, x; cin >> n >> q >> x;
    vector<ll> w(n), w_(2*n), c(n);
    ll S = 0;
    rep(i, 0, n){
        cin >> w[i];
        S += w[i];
    }
    rep(i, 0, 2*n){
        w_[i] = w[i%n];
    }

    ll rest = x%S;
    int r = 0, s = 0;
    rep(l, 0, n){
        if(r < l) r = l, s = 0;
        while(s < rest){
            s += w_[r];
            r++;
        }
        c[l] = r-l;
        s -= w[l];
    }

    vector<int> p, seen(n, -1);
    int npos = 0, cnt = 0, m = 0;

    while(seen[npos] < 0){
        seen[npos] = cnt;
        p.push_back(npos);
        npos = (npos+c[npos])%n;
        cnt++;
    }
    m = seen[npos];

    while(q--){
        ll k; cin >> k;
        k--;
        ll ans = n*(x/S);
        if(k < m) ans += c[p[k]];
        else ans += c[p[m+(k-m)%(p.size()-m)]];
        cout << ans << endl;
    }







    return 0;
}