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
    int n, q; cin >> n >> q;
    vector<ll> b(n);
    vector<ll> mx(n, 0);
    rep(i, 0, q){
        int id, x; cin >> id >> x; id--;
        b[id] += x;
        if(id < n-1) chmax(mx[id+1], b[id]-b[id+1]);
    }

    ll ans = 1;
    ll sum = 1;
    rep(i, 1, n){
        // cout << sum+mx[i]+1 << endl;
        ans += sum+mx[i]+1;
        sum += mx[i]+1; 
    }
    cout << ans << endl;
    return 0;
}