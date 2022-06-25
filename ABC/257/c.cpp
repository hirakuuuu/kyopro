#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc257/tasks/abc257_c

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> w(n), wc, wa;
    rep(i, 0, n){
        cin >> w[i];
        if(s[i] == '0') wc.push_back(w[i]);
        else wa.push_back(w[i]);
    }
    sort(wc.begin(), wc.end());
    sort(wa.begin(), wa.end());
    int ans = max(wa.size(), wc.size());
    int len = wa.size();
    rep(i, 0, len){
        int st = wa[i];
        int pos = lower_bound(wc.begin(), wc.end(), st)-wc.begin();
        ans = max(ans, pos+(len-i));
    }
    cout << ans << endl;
    
    return 0;
}