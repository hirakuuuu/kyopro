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
    int n; cin >> n;
    vector<ll> k(n), a(n);
    vector<pair<ll, ll>> mx(n, {-1, -1});
    rep(i, 0, n){
        cin >> k[i] >> a[i]; k[i]--;
        if(mx[k[i]].first < a[i]){
            swap(mx[k[i]].first, mx[k[i]].second);
            mx[k[i]].first = a[i];
        }else if(mx[k[i]].second < a[i]){
            mx[k[i]].second = a[i];
        }
    }

    
    return 0;
}