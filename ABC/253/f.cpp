#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc253/tasks/abc253_f

ll n, m, q;

vector<ll> bit(200005, 0);
void add(ll a, ll w){
    a++;
    for(ll x = a; x <= m; x += (x & -x)) bit[x] += w;
}

ll sum(ll a){
    ll ret = 0;
    for(ll x = a; x > 0; x -= (x & -x)) ret += bit[x];
    return ret;
}

int main(){
    cin >> n >> m >> q;
    vector<ll> t(q), a(q), b(q), c(q);
    vector<vector<ll>> subt(q);
    vector<pll> latest(n, pair(-1, 0));
    vector<ll> ans;

    rep(i, 0, q){
        cin >> t[i];
        if(t[i] == 1){
            cin >> a[i] >> b[i] >> c[i];
            a[i]--;
        }else if(t[i] == 2){
            cin >> a[i] >> b[i];
            a[i]--;
            latest[a[i]] = {i, b[i]};
        }else{
            cin >> a[i] >> b[i];
            a[i]--;
            c[i] = ans.size();
            ans.push_back(latest[a[i]].second);
            if(latest[a[i]].first >= 0) subt[latest[a[i]].first].push_back(i);
        }
    }

    rep(i, 0, q){
        if(t[i] == 1){
            add(a[i], c[i]);
            add(b[i], -c[i]);
        }else if(t[i] == 2){
            for(auto j: subt[i]){
                ans[c[j]] -= sum(b[j]);
            }
        }else{
            ans[c[i]] += sum(b[i]);
        }
    }

    for(auto x: ans){
        cout << x << "\n";
    }


    
    return 0;
}