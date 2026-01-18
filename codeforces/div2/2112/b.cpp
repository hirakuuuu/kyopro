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
        int n; cin >> n;
        vector<int> a(n);
        rep(i, 0, n) cin >> a[i];
        int ans = IINF;
        rep(i, 0, n-1){
            if(abs(a[i]-a[i+1]) <= 1){
                ans = 0;
                break;
            }
        }

        rep(l, 0, n-1){
            int mi = a[l], mx = a[l];
            rep(r, l+2, n+1){
                chmin(mi, a[r-1]);
                chmax(mx, a[r-1]);
                if(l > 0){
                    if(mi-1 <= a[l-1] && a[l-1] <= mx+1){
                        chmin(ans, r-l-1);
                    }
                }
                if(r < n){
                    if(mi-1 <= a[r] && a[r] <= mx+1){
                        chmin(ans, r-l-1);
                    }
                }
            }
        }
        if(ans == IINF) ans = -1;
        cout << ans << endl;

    }
    return 0;
}