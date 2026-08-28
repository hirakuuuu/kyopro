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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        ll n; cin >> n;
        if(n == 0) break; 
        string s; cin >> s;
        s = "1"+s;
        ll x = 0;
        rep(i, 0, s.size()){
            x += (1LL<<((int)s.size()-1-i))*(s[i]-'0');
        }
        ll y = x;
        int e = 0;
        while(n && !s.empty()){
            ll ok = 0, ng = 1LL<<53;
            while(ng-ok > 1){
                ll mid = (ok+ng)/2;
                if((__int128_t)x+(__int128_t)y*mid < 1LL<<53){
                    ok = mid;
                }else{
                    ng = mid;
                }
            }
            if(n <= ok){
                x += n*y;
                n = 0;
                break;
            }else{
                n -= ok+1;
                x += (ok+1)*y;
                x >>= 1;
                e++;
            }
            s.pop_back();
            y = 0;
            rep(i, 0, s.size()){
                y += (1LL<<((int)s.size()-1-i))*(s[i]-'0');
            }
        }
        // cout << n << endl;

        rrep(i, 11, 0){
            if(e>>i&1) cout << 1;
            else cout << 0;
        }
        rrep(i, 51, 0){
            if(x>>i&1) cout << 1;
            else cout << 0;
        }
        cout << endl;



    }
    
    return 0;
}