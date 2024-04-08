#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        ll n, x, y; cin >> n >> x >> y;
        vector<int> v(x);
        rep(i, 0, x) cin >> v[i];
        sort(v.begin(), v.end());
        ll ans = x;
        rep(i, 0, x-1){
            if(v[i+1]-v[i] == 2) ans++;
        }
        if((n+v[0]-v[x-1]) == 2) ans++;
        cout << ans-2 << endl;
    }
    
    return 0;
}