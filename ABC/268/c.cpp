#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc268/tasks/abc268_c

int main(){
    int n; cin >> n;
    vector<int> p(n), pos(n);
    rep(i, 0, n){
        cin >> p[i];
        pos[p[i]] = i;
    }

    vector<int> sat(n);

    rep(i, 0, n){
        int cnt = i-pos[i];
        if(i < pos[i]) cnt = n-(pos[i]-i);
        sat[cnt]++;
        sat[(cnt+1)%n]++;
        sat[(n+cnt-1)%n]++;
    }

    int ans = 0;

    rep(i, 0, n){
        ans = max(ans, sat[i]);
    }

    cout << ans << endl;
    
    return 0;
}