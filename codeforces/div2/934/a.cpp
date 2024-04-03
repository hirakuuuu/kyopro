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


int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int ans = 0;
        rep(i, 1, n/2+1){
            if(i*(n-i)-i*(i-1)/2 <= k) chmax(ans, max(i, n-i));
        }
        cout << n-ans << endl;
    }
 
    return 0;
}