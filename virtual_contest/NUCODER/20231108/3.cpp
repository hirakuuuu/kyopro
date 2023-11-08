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
    int h, w; cin >> h >> w;
    vector<string> s(h+1);
    rep(i, 0, h) cin >> s[i];
    rep(i, 0, h) s[i] += '.';
    rep(i, 0, w+1) s[h] += '.';
    ll ans = 0;

    rep(i, 0, h){
        rep(j, 0, w){
            int cnt = 0;
            cnt += (s[i][j] == '#');
            cnt += (s[i+1][j] == '#');
            cnt += (s[i][j+1] == '#');
            cnt += (s[i+1][j+1] == '#');
            if(cnt%2 == 1) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}