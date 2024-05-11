#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    vector<vector<ll>> y(2000005);
    for(ll i = 1; i <= 2000005; i++){
        for(ll j = 1; j*j <= i; j++){
            if(i%j == 0){
                y[i].push_back(j);
                if(i/j != j) y[i].push_back(i/j);
            }
            sort(y[i].begin(), y[i].end());
        }
    }
    while(t--){

    }
    return 0;
}