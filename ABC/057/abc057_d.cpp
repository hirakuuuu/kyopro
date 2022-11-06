#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc057/tasks/abc057_d

ll c[100][100];

ll combination(ll n, ll k){
    if(c[n][k] > 0) return c[n][k];
    if(k == 0 or n == k) return c[n][k] = 1;
    return c[n][k] = combination(n-1, k)+combination(n-1, k-1);
}

int main(){
    int n, a, b; cin >> n >> a >> b;
    vector<ll> v(n+1);
    rep(i, 1, n+1) cin >> v[i];
    sort(v.begin()+1, v.end(), greater<ll>());
    ll s = 0;
    rep(i, 1, a+1) s += v[i];

    map<ll, ll> m_cnt, m_pos;
    rep(i, 1, n+1){
        m_cnt[v[i]]++;
        if(m_pos[v[i]] == 0) m_pos[v[i]] = i;
    }

    ll ans = 0;

    rep(i, a, b+1){
        ll t = 0;
        rep(j, 1, i+1) t += v[j];
        if(s*i == t*a){
            ans += combination(m_cnt[v[i]], i-m_pos[v[i]]+1);
        }
    }

    printf("%.10f\n", (double)s/a);
    cout << ans << endl;

    
    return 0;
}