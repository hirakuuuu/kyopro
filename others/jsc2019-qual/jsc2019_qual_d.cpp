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
// https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_d

vector<vector<int>> ans(505, vector<int>(505));
void dfs(int l, int r, int d){
    if(r-l <= 1) return;
    int l1 = l, r1 = (r+l+1)/2;
    int l2 = (r+l+1)/2, r2 = r;
    rep(i, l1, r1){
        rep(j, l2, r2){
            ans[i][j] = d;
        }
    }
    dfs(l1, r1, d+1);
    dfs(l2, r2, d+1);
}

int main(){
    int n; cin >> n;
    int cnt = 0;
    while(1<<cnt < n) cnt++;
    dfs(1, n+1, 1);
    rep(i, 1, n){
        rep(j, i+1, n+1){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;
}