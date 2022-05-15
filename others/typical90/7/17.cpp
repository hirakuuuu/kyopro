#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_q

/*
余事象を考える、そしてフェニック木で高速化
*/


ll n, m;

vector<ll> bit(300005, 0);
void add(int a, int w){
    for(int x = a; x <= n; x += (x & -x)) bit[x] += w;
}

ll sum(int a){
    ll ret = 0;
    for(int x = a; x > 0; x -= (x & -x)) ret += bit[x];
    return ret;
}

int main(){
    cin >> n >> m;
    vector<pii> e(m);
    rep(i, 0, m){
        ll l, r; cin >> l >> r;
        e[i] = {r, l};
    }
    sort(e.begin(), e.end());

    // 1つ目の余事象
    vector<ll> cnt(n+1);
    rep(i, 0, m){
        cnt[e[i].first]++;
        cnt[e[i].second]++;
    }
    ll ans1 = 0;
    rep(i, 1, n+1){
        ans1 += cnt[i]*(cnt[i]-1)/2;
    }

    // 2つ目の余事象
    vector<ll> v(n+1);
    rep(i, 0, m){
        v[e[i].first]++;
    }
    rep(i, 1, n+1){
        v[i] += v[i-1];
    }
    ll ans2 = 0;
    rep(i, 0, m){
        ans2 += v[e[i].second-1];
    }

    // 3つ目の余事象
    ll ans3 = 0;
    rep(i, 0, m){
        ans3 += i-sum(e[i].second);
        add(e[i].second, 1);
    }
    
    cout << m*(m-1)/2 - (ans1+ans2+ans3) << endl;


    
    return 0;
}