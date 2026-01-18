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
        int n, m; cin >> n >> m;
        vector<bool> b(n+1);
        vector<int> seen(n+1);
        rep(i, 0, m){
            int a; cin >> a;
            bool ng = false;
            for(int j = 1; j*j <= a; j++){
                if(a%j == 0){
                    ng |= (seen[j] || seen[a/j]);
                } 
            }
            int ans = 0;

            if(!ng){
                for(int j = a; j <= n; j += a){
                    if(b[j]) continue;
                    b[j] = true;
                    ans++;
                }
            }
            if(ans == 0){
                cout << "the lights are already on!" << endl;
            }else{
                cout << ans << endl;
            }
            seen[a] = true;
        }
    }
    return 0;
}