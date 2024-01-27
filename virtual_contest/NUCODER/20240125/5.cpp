#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<ll> x(n), y(n);
        rep(i, 0, n) cin >> x[i] >> y[i];
        ll ans = x[0];
        if(x[0] >= 0) ans = x[0]*(y[0]*(y[0]+1)/2);
        ll sum = x[0]*y[0];
        ll tmp = x[0]*(y[0]*(y[0]+1)/2);
        rep(i, 1, n){
            if(x[i] > 0){
                chmax(ans, tmp+max(0LL, sum*y[i]+x[i]*(y[i]*(y[i]+1)/2)));
            }else if(x[i] < 0){
                ll d;
                if((x[i]+2*sum)*(2*x[i]) >= 0) d = -(((x[i]+2*sum))/(2*x[i])+1);
                else d = -(((x[i]+2*sum))/(2*x[i])); 
                // cout << d << endl;
                if(d < 0 || y[i] < d) chmax(ans, tmp+max(0LL, sum*y[i]+x[i]*(y[i]*(y[i]+1)/2)));
                else if(y[i] < d+1) chmax(ans, tmp+max({0LL, sum*d+x[i]*(d*(d+1)/2), sum*y[i]+x[i]*(y[i]*(y[i]+1)/2)}));
                else chmax(ans, tmp+max({0LL, sum*d+x[i]*(d*(d+1)/2), sum*(d+1)+x[i]*((d+1)*(d+2)/2), sum*y[i]+x[i]*(y[i]*(y[i]+1)/2)}));
            }else{
                chmax(ans, tmp+max(0LL, sum*y[i]+x[i]*(y[i]*(y[i]+1)/2)));
            }
            tmp += sum*y[i]+x[i]*(y[i]*(y[i]+1)/2);
            sum += x[i]*y[i];
            // cout << sum << ' ' << ans << ' ' << tmp << endl;
        }
        cout << ans << endl;
    }
    return 0;
}