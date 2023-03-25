#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc133/tasks/abc133_e

int n, k;
vector<vector<int>> g(100005);
vector<int> colored(100005);

ll dfs(int s, int pre=-1, int rest = k){
    ll res = rest;
    int used = 1;
    if(0 < pre) used++;

    for(auto ns: g[s]){
        if(ns != pre){
            res *= dfs(ns, s, k-used);
            res %= MOD;
            used++;
        }
    }
    return res;
}


int main(){
    cin >> n >> k;
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << dfs(1, -1, k) << endl;
    
    
    return 0;
}