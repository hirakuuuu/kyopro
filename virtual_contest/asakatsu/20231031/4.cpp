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
    int n, d; cin >> n >> d;
    vector<pair<ll, ll>> wall(n);
    rep(i, 0, n) cin >> wall[i].second >> wall[i].first;
    sort(wall.begin(), wall.end());
    int ans = 0, tmp = 0;
    rep(i, 0, n){
        auto [r, l] = wall[i];
        if(l <= tmp) continue;
        ans++;
        tmp = r+d-1;
    }
    cout << ans << endl;


    
    return 0;
}