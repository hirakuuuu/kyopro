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
    ll l, r, d, u; cin >> l >> r >> d >> u;
    ll ans = 0;
    if(r <= 0) l = -l, r = -r, swap(l, r);
    // cout << l << ' ' << r << endl;

    for(ll y = d; y <= u; y++){

        if(y%2 == 0){
            if(l >= 0){
                if(abs(y) < l){
                    if(l%2 == 0) ans += (r-l+2)/2;
                    else ans += (r-l+1)/2;
                }else if(abs(y) < r){
                    ans += abs(y)-l+1;
                    ans += (r-abs(y))/2;
                }else{
                    ans += r-l+1;
                }
            }else{
                ans++; // x = 0;
                if(r >= 1){
                    if(abs(y) < 1){
                        ans += r/2;
                    }else if(abs(y) < r){
                        ans += abs(y);
                        ans += (r-abs(y))/2;
                    }else{
                        ans += r;
                    }
                }
                if(l <= -1){
                    if(abs(y) < 1){
                        ans += abs(l)/2;
                    }else if(abs(y) < abs(l)){
                        ans += abs(y);
                        ans += (abs(l)-abs(y))/2;
                    }else{
                        ans += abs(l);
                    }
                }
            }
        }else{
            if(l >= 0){
                if(abs(y) < l){
                    if(l%2 == 0) ans += (r-l+2)/2;
                    else ans += (r-l+1)/2;
                }else if(abs(y) < r){
                    ans += (r-abs(y)+1)/2;
                }
            }else{
                if(r >= 1){
                    if(abs(y) < 1){
                        ans += r/2;
                    }else if(abs(y) < r){
                        ans += (r-abs(y)+1)/2;
                    }
                }
                if(l <= -1){
                    if(abs(y) < 1){
                        ans += abs(l)/2;
                    }else if(abs(y) < abs(l)){
                        ans += (abs(l)-abs(y)+1)/2;
                    }
                }
            }
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}