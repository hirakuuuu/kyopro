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
// https://atcoder.jp/contests/donuts-2015/tasks/donuts_2015_2

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> b(m);
    vector<vector<int>> c(m);
    rep(i, 0, m){
        cin >> b[i];
        int d; cin >> d;
        rep(j, 0, d){
            int e; cin >> e;
            c[i].push_back(e-1);
        }
    }

    ll ans = 0;

    rep(i, (1<<9)-1, (1<<n)){
        vector<int> bit;
        rep(j, 0, n){
            if((i&(1<<j)) > 0) bit.push_back(j);
        }
        if(bit.size() == 9){
            ll cnt = 0;
            rep(j, 0, n){
                cnt += ((i&(1<<j)) > 0) ? a[j] : 0;
            }
            rep(j, 0, m){
                int cnt_b = 0;
                for(auto cc: c[j]){
                    if((i&(1<<cc)) > 0) cnt_b++;
                }
                if(cnt_b >= 3) cnt += b[j];
            }

            chmax(ans, cnt);

        }
    }

        cout << ans << endl;
    
    return 0;
}