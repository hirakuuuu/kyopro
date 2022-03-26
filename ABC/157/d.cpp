#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc157/tasks/abc157_d

vector<int> par(100005, -1);

int root(int x){
    if(par[x] < 0) return x;
    else return par[x] = root(par[x]);
}

bool same(int x, int y){
    return root(x) == root(y);
}

void unite(int x, int y){
    if(same(x, y)) return;
    x = root(x);
    y = root(y);
    if(par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int size(int x){
    x = root(x);
    return -1*par[x];
}

int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> ans(n+1, -1);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        unite(a, b);
        ans[a]--;
        ans[b]--;
    }
    rep(i, 1, n+1){
        ans[i] += size(i);
    }
    rep(i, 0, k){
        int c, d; cin >> c >> d;
        if(same(c, d)){
            ans[c]--;
            ans[d]--;
        }
    }
    cout << ans[1];
    rep(i, 2, n+1){
        cout << ' ' << ans[i];
    }
    cout << endl;
}