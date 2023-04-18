#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, t; cin >> n >> t;
    vector<ll> a(40);
    rep(i, 0, n) cin >> a[i];

    set<ll> s;
    rep(i, 0, 1<<20){
        ll tmp = 0;
        rep(j, 0, 20){
            if((i&(1<<j)) > 0) tmp += a[j+20];
        }
        if(tmp > t) continue;
        s.insert(-tmp);
    }

    ll ans = 0;

    rep(i, 0, 1<<20){
        ll sum = 0;
        rep(j, 0, 20){
            if((i&(1<<j)) > 0) sum += a[j];
        }
        if(sum > t) continue;
        ll rest = *s.lower_bound(sum-t);
        chmax(ans, sum-rest);
    }
    cout << ans << endl;
    
    return 0;
}