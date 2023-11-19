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
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> a[i][j];
        }
    }

    int n = h+w-2, ans = 0;
    rep(i, 0, 1<<n){
        int cnt = 0;
        rep(j, 0, n){
            cnt += ((i>>j)&1);
        }
        if(cnt != w-1) continue;

        set<int> s;
        s.insert(a[0][0]);
        int ch = 0, cw = 0;
        rep(j, 0, n){
            if((i>>j)&1) cw++;
            else ch++;
            s.insert(a[ch][cw]);
        }
        if(s.size() == n+1) ans++;
    }
    cout << ans << endl;
    
    
    return 0;
}