#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc019/tasks/agc019_b

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> pos(26);
    rep(i, 0, n){
        pos[s[i]-'a'].push_back(i);
    }

    ll ans = 1;
    rep(i, 0, n){
        int same = pos[s[i]-'a'].end() - lower_bound(pos[s[i]-'a'].begin(), pos[s[i]-'a'].end(), i);
        ans += (i+1)-same;
    }
    cout << ans << endl;
    
    return 0;
}