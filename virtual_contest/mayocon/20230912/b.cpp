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

    int a, b, c, x; cin >> a >> b >> c >> x;
    int cnt = 0;
    rep(i, 0, a+1){
        rep(j, 0, b+1){
            rep(k, 0, c+1){
                if(500*i+100*j+50*k == x) cnt++;
            }
        }
    }
    cout << cnt << endl;
    
    return 0;
}