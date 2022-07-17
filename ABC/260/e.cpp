#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc260/tasks/abc260_e

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(n);
    vector<vector<int>> inv(m+1);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        inv[a[i]].push_back(i);
        inv[b[i]].push_back(i);
    }

    vector<ll> ans(m+2), cnt(n);
    ll r = 1, cnt_zero = n;
    rep(l, 1, m+1){
        while(r <= m and cnt_zero > 0){
            for(auto x: inv[r]){
                if(cnt[x] == 0) cnt_zero--;
                cnt[x]++;
            }
            r++;
        }

        if(cnt_zero > 0) break;

        ans[r-l]++;
        ans[m+1-l+1]--;

        for(auto x: inv[l]){
            cnt[x]--;
            if(cnt[x] == 0) cnt_zero++;
        }
    }

    rep(i, 1, m+1){
        ans[i] += ans[i-1];
        if(i > 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}