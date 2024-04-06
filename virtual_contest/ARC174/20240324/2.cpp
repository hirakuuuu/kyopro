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
        vector<ll> a(5), p(5);
        rep(i, 0, 5) cin >> a[i];
        rep(i, 0, 5) cin >> p[i];
        ll rest = -a[3]-2*a[4]+2*a[0]+a[1];
        if(rest <= 0){
            cout << 0 << endl;
            continue;
        }
        ll l = p[3]*rest, r = p[4]*((rest+1)/2);
        if(rest%2 == 0){
            cout << min(p[3]*rest, p[4]*(rest/2)) << endl;
        }else{
            cout << min({p[3]*rest, p[4]*((rest+1)/2), p[4]*(rest/2)+p[3]}) << endl;
        }

    }
    return 0;
}