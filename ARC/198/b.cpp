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
        ll x, y, z; cin >> x >> y >> z;
        if(z == 0){
            if(x < (y+1)/2){
                cout << "No" << endl;
            }else{
                if(y%2 == 0) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
            continue;
        }
        if(x < z){
            cout << "No" << endl;
            continue;
        }
        x -= z;

        // 0202...02
        y = max(0LL, y-z*2);
        // 1012101210101012
        if(x < (y+1)/2){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    
    return 0;
}