#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc259/tasks/abc259_e

int main(){
    int n; cin >> n;

    vector<ll> m(n+1);
    vector<vector<pll>> pe(n+1);
    map<ll, pll> p_cnt;
    rep(i, 1, n+1){
        cin >> m[i];
        rep(j, 0, m[i]){
            ll p, e; cin >> p >> e;
            pe[i].push_back({p, e});
            if(p_cnt[p].first < e){
                p_cnt[p] = {e, 1};            
            }else if(p_cnt[p].first == e){
                p_cnt[p].second++;
            }
        }
    }

    ll ans = 0, c = 0;
    
    rep(i, 1, n+1){
        bool f = false;
        rep(j, 0, m[i]){
            if(p_cnt[pe[i][j].first].first == pe[i][j].second and p_cnt[pe[i][j].first].second == 1){
                f = true;
            }
        }
        if(f) ans++;
        else c = 1;
    }

    cout << ans+c << endl;

    return 0;
}