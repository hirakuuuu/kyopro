#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc265/tasks/abc265_d

int main(){
    ll n, P, Q, R; cin >> n >> P >> Q >> R;
    vector<ll> a(n), ruiseki(n+1);
    rep(i, 0, n){
        cin >> a[i];
        ruiseki[i+1] = ruiseki[i]+a[i];
    }

    vector<ll> pos_p(n, -1);
    vector<ll> pos_q(n, -1);
    vector<ll> pos_r(n, -1);
    int pos;
    rep(i, 0, n){
        pos = lower_bound(ruiseki.begin(), ruiseki.end(), P+ruiseki[i])-ruiseki.begin();
        if(pos <= n and ruiseki[pos] == P+ruiseki[i]) pos_p[i] = pos;

        pos = lower_bound(ruiseki.begin(), ruiseki.end(), Q+ruiseki[i])-ruiseki.begin();
        if(pos <= n and ruiseki[pos] == Q+ruiseki[i]) pos_q[i] = pos;

        pos = lower_bound(ruiseki.begin(), ruiseki.end(), P+ruiseki[i])-ruiseki.begin();
        if(pos <= n and ruiseki[pos] == R+ruiseki[i]) pos_r[i] = pos;
    }

    // rep(i, 0, n){
    //     cout << pos_p[i] << " ";
    // }
    // cout << endl;
    // rep(i, 0, n){
    //     cout << pos_q[i] << " ";
    // }
    // cout << endl;
    // rep(i, 0, n){
    //     cout << pos_r[i] << " ";
    // }
    // cout << endl;


    rep(i, 0, n){
        ll l = pos_p[i], r = pos_p[i];
        if(l < n and pos_q[l] != -1){
            r = pos_q[l];
            l = r;
        }else continue;

        if(l < n and pos_r[l] != 1){
            r = pos_r[l];
            l = r;
        }else continue;

        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    
    return 0;
}