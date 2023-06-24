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
    int w, h, n; cin >> w >> h >> n;
    vector<int> b(4);
    b[0] = 0;
    b[1] = w;
    b[2] = 0;
    b[3] = h;
    rep(i, 0, n){
        int x, y, a; cin >> x >> y >> a;
        a--;
        if(a == 0) chmax(b[0], x);
        else if(a == 1) chmin(b[1], x);
        else if(a == 2) chmax(b[2], y);
        else if(a == 3) chmin(b[3], y);
    }

    int ans = (b[1]-b[0])*(b[3]-b[2]);
    if(b[1]-b[0] < 0 || b[3]-b[2] < 0) ans = 0;

    cout << ans << endl;

    
    return 0;
}