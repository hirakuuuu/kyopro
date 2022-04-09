#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc049/tasks/agc049_b

int main(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<int> ps, pt;
    rep(i, 0, n){
        if(s[i] == '1') ps.push_back(i);
        if(t[i] == '1') pt.push_back(i);
    }
    ps.push_back(n);
    pt.push_back(n);

    if(pt.size() > ps.size() or (pt.size()%2)^(ps.size()%2)){
        cout << -1 << endl;
        return 0;
    }

    int sl = 0, tl = 0;
    ll ans = 0;
    while(ps[sl] < n){
        if(pt[tl] <= ps[sl]){
            ans += ps[sl]-pt[tl];
            sl++;
            tl++;
        }else{
            ans += ps[sl+1]-ps[sl];
            sl += 2;
        }
    }
    if(pt[tl] < n) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}