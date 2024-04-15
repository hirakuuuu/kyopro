#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        rep(i, 0, n){
            cin >> a[i];
        }
        vector<int> ans(n);
        if(n == 2){
            while(a[0] && a[1]){
                rep(i, 0, n){
                    a[(i+1)%n] = max(0LL, a[(i+1)%n]-a[i]);
                }
            }
            rep(i, 0, n) if(a[i]) ans[i] = 1;
        }else if(n == 3){
            while(a[0] && a[1] && a[2]){
                rep(i, 0, n){
                    a[(i+1)%n] = max(0LL, a[(i+1)%n]-a[i]);
                }
            }
            rep(i, 0, n) if(!a[i] && a[(i+1)%n]) ans[(i+1)%n] = 1;
        }else{
            auto check = [&]() -> bool{
                rep(i, 0, n){
                    if(a[i] && a[(i+1)%n] && a[(i+2)%n] && a[(i+3)%n]) return true;
                }
                return false;
            };
            while(check()){
                rep(j, 0, n){
                    a[(j+1)%n] = max(0LL, a[(j+1)%n]-a[j]);
                }
            }
            rep(j, 0, n){
                if(a[j] && a[(j+1)%n]) a[(j+1)%n] = max(0LL, a[(j+1)%n]-a[j]);
                else break;
            }
            rep(i, 0, n){
                if(!a[i] && a[(i+1)%n]){
                    ans[(i+1)%n] = 1;
                    ll k = a[(i+2)%n]/a[(i+1)%n];
                    if(a[(i+3)%n] > (2*a[(i+2)%n]-(k+1)*a[(i+1)%n])*k/2){
                        ans[(i+3)%n] = 1;
                    }
                }
            }
        }
        int cnt = 0;
        rep(i, 0, n) cnt += ans[i];
        cout << cnt << '\n';
        rep(i, 0, n) if(ans[i]) cout << i+1 << ' ';
        cout << '\n';
    }



    
    return 0;
}