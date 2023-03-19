#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc294/tasks/abc294_f

vector<vector<int>> g(200005); //グラフの隣接リスト
vector<int> v; //オイラーツアーの頂点配列
vector<int> ind(n); //各頂点がオイラーツアー配列の何番目に最初に訪れるか

void dfs(int now, int par){//今の頂点、親の頂点
    ind[now] = v.size();
    v.push_back(now);
    for(int i = 0; i < g[now].size(); i++){
        if(g[now][i] != par){
            dfs(g[now][i],now);
            v.push_back(now);
        }
    }
}

int main(){
    ll n, m, k; cin >> n >> m >> k;
    vector<double> a(n), b(n), c(m), d(m);
    rep(i, 0, n) cin >> a[i] >> b[i];
    rep(i, 0, m) cin >> c[i] >> d[i];



    
    return 0;
}