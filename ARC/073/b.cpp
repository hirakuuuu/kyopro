#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc073/tasks/arc073_b

int main(){
    ll n, w; cin >> n >> w;
    vector<vector<ll>> v(4);
    ll sw, sv; cin >> sw >> sv;
    v[sw-sw].push_back(sv);
    rep(i, 1, n){
        ll W, V; cin >> W >> V;
        v[W-sw].push_back(V);
    }

    rep(i, 0, 4){
        sort(v[i].begin(), v[i].end(), greater<ll>());
    }

    ll ans = 0;

    rep(i, 0, v[0].size()+1){
        rep(j, 0, v[1].size()+1){
            rep(k, 0, v[2].size()+1){
                rep(l, 0, v[3].size()+1){
                    if((i+j+k+l)*sw+j+2*k+3*l > w) continue;
                    ll cnt = 0;
                    rep(x, 0, i) cnt += v[0][x];
                    rep(x, 0, j) cnt += v[1][x];
                    rep(x, 0, k) cnt += v[2][x];
                    rep(x, 0, l) cnt += v[3][x];
                    ans = max(ans, cnt);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}