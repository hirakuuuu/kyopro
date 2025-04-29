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
        ll n, k; cin >> n >> k;

        vector<int> zero;
        rep(i, 0, 32){
            if((1LL<<i) >= n) break;
            if(!((n>>i)&1)) zero.push_back(i);
        }

        k--;
        if((1LL<<(zero.size())) > k){
            // cout << zero.size() << endl;
            rep(i, 0, zero.size()){
                if((k>>i)&1){
                    // cout << zero[i] << endl;
                    n |= (1LL<<zero[i]);
                }
            }
            cout << n << endl;
        }else{
            cout << -1 << endl;
        }

    }

    // rep(n, 1, 101){
    //     cout << n << ": ";
    //     rep(x, 1, 200){
    //         if((n^x) == x%n) cout << x << ", ";
    //     }
    //     cout << endl;
    // }
    
    return 0;
}