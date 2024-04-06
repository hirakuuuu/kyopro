#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/pakencamp-2023-day1/tasks/e

int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt_odd = 0;
    rep(i, 0, n){
        if(g[i].size()%2) cnt_odd++;
    }
    if(k%2){
        if(cnt_odd <= 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    
    return 0;
}