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
// https://atcoder.jp/contests/abc175/tasks/abc175_d

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> p(n+1), c(n+1);
    ll ans = -1e9;
    rep(i, 1, n+1) cin >> p[i];
    rep(i, 1, n+1){
        cin >> c[i];
        ans = max(ans, c[i]);
    }

    vector<ll> s(n);
    vector<ll> s_max(n);
    rep(i, 1, n+1){
        ll pos = i, cnt = 0;
        while(p[pos] != i){
            pos = p[pos];
            cnt++;
            s[cnt] = s[cnt-1]+c[pos];

            if(cnt == 1) s_max[cnt] = c[pos];
            else s_max[cnt] = max(s[cnt], s_max[cnt-1]);
        }

        if(s[cnt]+c[i] > 0){
            if(k/(cnt+1) > 0){
                ans = max(ans, (s[cnt]+c[i])*(k/(cnt+1))+max(0LL, s_max[k%(cnt+1)]));
                ans = max(ans, (s[cnt]+c[i])*(k/(cnt+1)-1)+max(0LL, s_max[cnt]));
            }else{
                ans = max(ans, s_max[k%(cnt+1)]);
            }
        }else{
            ans = max(ans, s_max[cnt]);
        }
    }

    cout << ans << endl;


    


    
    return 0;
}