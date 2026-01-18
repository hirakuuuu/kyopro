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
        int a, x, y; cin >> a >> x >> y;
        bool ok = false;
        for(int i = -201; i <= 201; i++){
            if(i >= 0){
                if(abs(a-x) > abs(i-x) && abs(a-y) > abs(i-y)){
                    ok = true;
                    break;
                }
            }else{
                if(abs(a-x) > abs(-i+x) && abs(a-y) > abs(-i+y)){
                    ok = true;
                    break;
                }
            }

        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}