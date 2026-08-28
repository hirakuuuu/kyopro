#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, t; cin >> n >> t;
    int ans = 0;
    rep(i, 0, t){
        pair<int, int> mx;
        rep(j, 0, n){
            int s; cin >> s;
            if(mx.first <= s){
                mx.second = mx.first;
                mx.first = s;
            }else if(mx.second <= s){
                mx.second = s;
            }
        }
        if(mx.first >= mx.second*2) ans++;
    }
    cout << ans << endl;
    return 0;
}