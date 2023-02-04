#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
// 問題
// https://atcoder.jp/contests/abc288/tasks/abc288_d


int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    vector<int> sum(n+1);
    rep(i, 1, k+1) sum[i] = a[i];
    rep(i, k+1, n+1){
        sum[i] = sum[i-k]+a[i];
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        if(k == 1){
            cout << "Yes" << endl;
        }else{
            bool f = true;
            int need = sum[r]-sum[max(0, r-k*((r-l+k)/k))];
            rep(i, 1, k){
                if(need != sum[r-i]-sum[max(0, r-i-k*((r-i-l+k)/k))]) f = false;
            }
            if(f) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    return 0;
}