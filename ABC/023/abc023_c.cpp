#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc023/tasks/abc023_c

int main(){
    int r, c, k; cin >> r >> c >> k;
    int n; cin >> n;
    vector<int> h(n), w(n);
    vector<int> cnt_r(r), cnt_c(c);
    
    rep(i, 0, n){
        cin >> h[i] >> w[i];
        h[i]--, w[i]--;
        cnt_r[h[i]]++;
        cnt_c[w[i]]++;
    }

    ll ans = 0;
    // アメがあるマスを選んでk個にできるか
    rep(i, 0, n){
        if(cnt_r[h[i]]+cnt_c[w[i]]-1 == k) ans++;
    }

    vector<int> cnt_k1(r);
    
    rep(i, 0, n){
        if(cnt_r[h[i]]+cnt_c[w[i]] == k) cnt_k1[h[i]]++;
    }
    sort(cnt_r.begin(), cnt_r.end());
    sort(cnt_c.begin(), cnt_c.end());

    rep(i, 0, r){
        int tmp = cnt_r[i];
        int cnt = upper_bound(cnt_c.begin(), cnt_c.end(), k-tmp)-lower_bound(cnt_c.begin(), cnt_c.end(), k-tmp);
        ans += cnt-cnt_k1[i];
    }
    cout << ans << endl;

    
    return 0;
}