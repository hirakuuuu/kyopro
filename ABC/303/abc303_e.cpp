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
// https://atcoder.jp/contests/abc303/tasks/abc303_e

int main(){
    int n; cin >> n;
    vector<int> degree(n+1);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    vector<int> ans;
    int rest = n;
    rep(i, 1, n+1){
        if(degree[i] >= 3){
            ans.push_back(degree[i]);
            rest -= degree[i]+1;
        }
    }

    while(rest > 0){
        ans.push_back(2);
        rest -= 3;
    }
    sort(ans.begin(), ans.end());
    for(auto a: ans){
        cout << a << ' ';
    }
    cout << endl;
    
    return 0;
}