#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc256/tasks/abc256_d

int main(){
    int n; cin >> n;
    vector<pii> lr(n);
    rep(i, 0, n){
        int L, R; cin >> L >> R;
        lr[i] = {L, R};
    }

    sort(lr.begin(), lr.end());


    vector<pii> ans;
    int l = lr[0].first, r = lr[0].second;
    rep(i, 1, n){
        if(r < lr[i].first){
            ans.push_back({l, r});
            l = lr[i].first;
            r = lr[i].second;
        }else{
            r = max(r, lr[i].second);
        }
    }
    ans.push_back({l, r});
    rep(i, 0, ans.size()){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    
    return 0;
}