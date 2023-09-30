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
// https://atcoder.jp/contests/arc151/tasks/arc151_c

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> x(m), y(m);
    rep(i, 0, m) cin >> x[i] >> y[i];

    if(m == 0){
        if(n%2) cout << "Takahashi" << endl;
        else cout << "Aoki" << endl;
        return 0;
    }

    ll f = (x[0]-1)^(n-x[m-1]);
    rep(i, 1, m){
        f ^= (y[i] == y[i-1]);
    }

    if(f) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;


    
    return 0;
}