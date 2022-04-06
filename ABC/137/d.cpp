#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc137/tasks/abc137_d

int main(){
    int n, m; cin >> n >> m;
    priority_queue<int> que;
    vector<vector<int>> s(100005);
    rep(i, 0, n){
        int a, b; cin >> a >> b;
        s[a].push_back(b);
    }
    int d = 1;
    ll ans = 0;
    while(d <= m){
        for(int ss: s[d]){
            que.push(ss);
        }
        if(que.size()){
            int q = que.top(); que.pop();
            ans += q;
        } 
        d++;
    }
    cout << ans << endl;
    return 0;
}