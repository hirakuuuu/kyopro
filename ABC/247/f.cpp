#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc247/tasks/abc247_f

vector<ll> d(200005);
ll f(int n){
    if(n == 1) return 2;
    if(n == 2) return 3;
    if(d[n]) return d[n];
    d[n] = (f(n-1)+f(n-2))%mod;
    return d[n];
}

ll g(int n){
    if(n == 1) return 1;
    if(n == 2) return 3;
    if(n == 3) return 4;
    return f(n-1)+f(n-3);
}

vector<ll> par(200005, -1);

int root(ll x){
    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
}

bool same(ll x, ll y){
    return root(x) == root(y);
}

int size(ll x){
    x = root(x);
    return (-1)*par[x];
}

void unite(ll x, ll y){
    x = root(x);
    y = root(y);
    if(x == y) return;
    if(size(x) < size(y)) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int main(){
    int n; cin >> n;
    vector<ll> p(n), q(n);
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) cin  >> q[i];
    rep(i, 0, n){
        unite(p[i], q[i]);
    }

    map<ll, bool> m;
    ll ans = 1;
    rep(i, 1, n+1){
        int r = root(i);
        if(!m[r]){
            m[r] = true;
            if(par[r] == -1) continue;
            ans = (ans*g(size(r))%mod);
        }
    }
    cout << ans << endl;
    return 0;
}