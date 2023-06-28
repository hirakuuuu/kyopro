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
    ll n, d; cin >> n >> d;
    vector<pll> w(n);
    rep(i, 0, n){
        cin >> w[i].second >> w[i].first;
        w[i].second *= -1;
    }
    sort(w.begin(), w.end());
    rep(i, 0, n) w[i].second *= -1;
    
    int ans = 0;
    ll max_r = 0;
    rep(i, 0, n){
        auto [r, l] = w[i];
        if(max_r < l){
            ans++;
            max_r = r+d-1;
        }
    }
    cout << ans << endl;
    return 0;
}