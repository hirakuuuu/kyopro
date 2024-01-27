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
    vector<int> a(26);
    int cnt_o = 0, oi = -1;
    rep(i, 0, 26){
        cin >> a[i];
        cnt_o += a[i]%2;
        if(a[i]%2) oi = i;
    }
    if(cnt_o >= 2){
        cout << -1 << endl;
        return 0;
    }
    string ans;
    rep(i, 0, 26){
        rep(j, 0, a[i]/2) ans += 'A'+i;
    }
    if(oi >= 0) ans += 'A'+oi;
    rrep(i, 25, 0){
        rep(j, 0, a[i]/2) ans += 'A'+i;
    }
    cout << ans << endl;

    
    return 0;
}