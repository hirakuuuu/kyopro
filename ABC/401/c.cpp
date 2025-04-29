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
    ll M = 1000000000;
    int n, k; cin >> n >> k;
    vector<ll> a(n+1);
    ll sum = 0;
    rep(i, 0, n+1){
        if(i < k){
            a[i] = 1;
            sum += a[i];
            sum %= M;
        }else{
            a[i] = sum;
            sum += a[i];
            sum %= M;
            sum -= a[i-k];
            if(sum < 0) sum += M;
        }
    }
    cout << a[n] << endl;
    return 0;
}