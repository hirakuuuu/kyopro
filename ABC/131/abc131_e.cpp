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
// https://atcoder.jp/contests/abc131/tasks/abc131_e

int main(){
    int n, k; cin >> n >> k;
    int mx = (n-1)*(n-2)/2;

    // 不可能
    if(mx < k){
        cout << -1 << endl;
        return 0;
    }

    // 最大の個数のグラフから1つずつ減らしてｋにする
    vector<pair<int, int>> edge;
    rep(i, 1, n){
        edge.push_back({i, n});
    }
    rep(i, 1, n){
        rep(j, i+1, n){
            edge.push_back({i, j});
        }
    }

    cout << n-1+(mx-k) << endl;
    rep(i, 0, n-1+(mx-k)){
        cout << edge[i].first << ' ' << edge[i].second << endl;
    }

    return 0;
}