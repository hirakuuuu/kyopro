#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc206/tasks/abc206_d

vector<int> par(200005, -1);

int root(int x){
    if(par[x] < 0) return x;
    else return par[x] = root(par[x]);
}

bool same(int x, int y){
    return root(x) == root(y);
}

void unite(int x, int y){
    x = root(x), y = root(y);
    if(x == y) return;
    if(par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int size(int x){
    x = root(x);
    return -par[x];
}


int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i];
        b[n-i-1] = a[i];
    }
    rep(i, 0, n){
        unite(a[i], b[i]);
    }

    int ans = 0;
    vector<int> f(200005, 0);
    rep(i, 0, n){
        int r = root(a[i]);
        if(f[r] == 0){
            f[r] = 1;
            ans += size(r)-1;
        }
    }
    cout << ans << endl;
    
    return 0;
}