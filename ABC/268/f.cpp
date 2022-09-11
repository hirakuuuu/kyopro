#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc268/tasks/abc268_f

int main(){
    int n; cin >> n;
    vector<string> s(n);
    vector<pair<double, int>> p(n);
    rep(i, 0, n){
        cin >> s[i];
        double x = 0, y = 0;
        for(auto ss: s[i]){
            if(ss == 'X') x++;
            else y += ss-'0';
        }
        
        double score = 0;
        if(x == 0) score = pow(10, 9)+7;
        else score = y/x;

        p[i] = {score, i};
    }

    sort(p.begin(), p.end());

    ll ans = 0, x_cnt = 0;
    rep(i, 0, n){
        int id = p[i].second;
        for(auto ss: s[id]){
            if(ss == 'X') x_cnt++;
            else ans += x_cnt*(ss-'0');
        }
    }

    cout << ans << endl;

    return 0;
}