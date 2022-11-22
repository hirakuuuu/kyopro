#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_c

int main(){
    ll w, h; cin >> w >> h;
    vector<ll> p(w), q(h);
    vector<pll> r(w+h);
    rep(i, 0, w){
        cin >> p[i];
        r[i] = {p[i], 0};
    }
    rep(i, 0, h){
        cin >> q[i];
        r[w+i] = {q[i], 1};
    }

    sort(r.begin(), r.end());

    ll ans = 0;
    ll cnt_c = 0, cnt_r = 0;
    rep(i, 0, w+h){
        if(r[i].second == 0){
            ans += r[i].first*(h+1-cnt_r);
            cnt_c++;
        }else{
            ans += r[i].first*(w+1-cnt_c);
            cnt_r++;
        }
    }

    cout << ans << endl;

    
    return 0;
}