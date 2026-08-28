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
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<vector<ll>> a(n, vector<ll>(n));
        ll g = 0;
        rep(i, 0, n){
            rep(j, 0, n){
                cin >> a[i][j];
                if((i+j)%2) g ^= a[i][j]%(k+1);
            }
        }
        if(g) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    
    return 0;
}