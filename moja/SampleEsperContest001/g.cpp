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

// オイラーのφ関数
ll euler_phi(ll n){
    ll ret = n;
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            ret -= ret/i;
            while(n%i == 0) n /= i;
        }
    }
    if(n > 1) ret -= ret/n;
    return ret;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> phi(1000005);
    rep(i, 1, 1000005) phi[i] = euler_phi(i);


    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        cout << (ll)phi[x]*x/2 << endl;
    }
    return 0;
}