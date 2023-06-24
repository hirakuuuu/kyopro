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
    ll n, k; cin >> n >> k;
    vector<vector<ll>> t(n, vector<ll>(n));
    rep(i, 0, n){
        rep(j, 0, n) cin >> t[i][j];
    }

    vector<int> jun(n);
    iota(jun.begin(), jun.end(), 0);

    ll ans = 0;

    do{
        if(jun[0] != 0) break;
        ll cost = 0;
        rep(i, 0, n) cost += t[jun[i]][jun[(i+1)%n]];

        if(cost == k) ans++; 

    }while(next_permutation(jun.begin(), jun.end()));

    cout << ans << endl;
    
    return 0;
}