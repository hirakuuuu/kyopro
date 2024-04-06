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
        v.push_back(n+v[0]);
        ll ans = x-2;
        vector<ll> odd, even;
        rep(i, 0, x){
            ll tmp = v[i+1]-v[i]-1;
            if(tmp == 1){
                ans++;
            }else{
                if(tmp%2 == 0) even.push_back(tmp);
                else odd.push_back(tmp);
            }
        }
        sort(odd.begin(), odd.end());
        int id = 0;
        while(y && id < (int)odd.size()){
            if(odd[id]/2 <= y){
                ans += odd[id];
                y -= odd[id]/2;
            }else{
                ans += y*2;
                y = 0;
            }
            id++;
        }
        id = 0;
        while(y && id < (int)even.size()){
            if(even[id]/2 <= y){
                ans += even[id];
                y -= even[id]/2;
            }else{
                ans += y*2;
                y = 0;
            }
            id++;
        }
        cout << ans << endl;
    }
    
    return 0;
}