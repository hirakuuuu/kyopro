#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_b


int main(){
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> b(n*(n+1)/2);
    int id = 0;
    rep(i, 0, n){
        b[id] = a[i];
        id++;
        rep(j, i+1, n){
            b[id] = b[id-1]+a[j];
            id++;
        }
    }

    // 各桁における1の数
    vector<ll> d(50);
    for(auto bb: b){
        ll c = bb;
        rep(i, 0, 50){
            if(c&(1LL<<i)) d[i]++;
        }
    }


    ll ans = 0;
    int M = 50, m = -1;
    while(true){
        m = -1;
        rep(i, 0, M){
            if(d[M-i-1] >= k){
                m = M-i-1;
                break;
            }
        }
        if(m < 0) break;
        M = m;
        ans += (1LL<<m);
        vector<ll> nb, nd(50);
        for(auto bb: b){
            if(bb&(1LL<<m)) nb.push_back(bb);
        }
        b = nb;
        for(auto bb: b){
            ll c = bb;
            rep(i, 0, 50){
                if(c&(1LL<<i)) nd[i]++;
            }
        }
        d = nd;
    }
    cout << ans << endl;  
}