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

int main(){
    int n; cin >> n;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> sum(n+1);
    rep(i, 1, n+1) sum[i] = a[i]+sum[i-1];

    int ans = 1;
    rep(i, 1, n){
        if(2*sum[n-i] < a[n-i+1]) break;
        ans++;
    }

    cout << ans << endl;

    
    return 0;
}