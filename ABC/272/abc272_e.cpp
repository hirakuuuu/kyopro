#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc272/tasks/abc272_e

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    vector<vector<int>> b(m+1);
    rep(i, 1, n+1){
        if(a[i] > n) continue;
        int l = (a[i] >= 0 ? 1 : (-a[i]+i-1)/i);
        int r = min(m, (n-a[i]+i-1)/i);
        rep(j, l, r+1) b[j].push_back(a[i]+i*j);
    }


    rep(i, 1, m+1){
        vector<int> exist(b[i].size()+1);
        for(auto bb: b[i]){
            if(bb <= b[i].size()) exist[bb]++;
        }

        int ans = 0;
        while(exist[ans]) ans++;
        cout << ans << endl;
    }

    
    return 0;
}