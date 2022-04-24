#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc146/tasks/abc146_f

int main(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    reverse(s.begin(), s.end());
    vector<int> ans;

    int p = 0;
    while(p < n){
        int r = min(p+m, n);
        bool f = true;
        for(int i = r; i > p; i--){
            if(s[i]-'0') continue;
            ans.push_back(i-p);
            p = i;
            f = false;
            break;
        }
        if(f){
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    rep(i, 0, ans.size()){
        if(i > 0) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}