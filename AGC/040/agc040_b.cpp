#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/agc040/tasks/agc040_b

int main(){
    int n; cin >> n;
    vector<int> l(n), r(n);
    int mx = 0, mn = 2e9;
    rep(i, 0, n){
        cin >> l[i] >> r[i];
        l[i]--;
        chmax(mx, l[i]);
        chmin(mn, r[i]);
    }

    // mxとmnを同じグループにする場合
    int ans = 0;
    rep(i, 0, n){
        chmax(ans, max(0, mn-mx)+r[i]-l[i]);
    }

    // mxとmnを異なるグループにする場合
    vector<pii> t(n);
    rep(i, 0, n){
        t[i] = {max(0, mn-l[i]), -max(0, r[i]-mx)};
    }

    sort(t.begin(), t.end());
    int w = 2e9;

    rep(i, 0, n){
        pii z = t[i];
        z.second = -z.second;
        if(i > 0) chmax(ans, w+z.first);
        chmin(w, z.second);
    }

    cout << ans << endl;

    
    return 0;
}