#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc045/tasks/arc061_b

vector<ll> dh = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
vector<ll> dw = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

bool check(ll i, ll j, ll h, ll w){
    return (0 < i and i < h and 0 < j and j < w);
}

int main(){
    ll h, w, n; cin >> h >> w >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    map<pll, ll> cnt;
    rep(i, 0, n){
        rep(j, 0, 9){
            ll nh = a[i]+dh[j], nw = b[i]+dw[j];
            if(check(nh, nw, h-1, w-1)){
                cnt[{nh, nw}]++;
            }
        }
    }

    vector<ll> ans(10);
    ll total = (h-2)*(w-2);
    for(const auto &c: cnt){
        ans[c.second]++;
        total--;
    }
    ans[0] = total;

    rep(i, 0, 10){
        cout << ans[i] << endl;
    }
    
    return 0;
}