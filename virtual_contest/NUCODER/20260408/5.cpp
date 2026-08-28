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
constexpr ll INF = 2e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string x; cin >> x;
    int n = x.size();
    ll m; cin >> m;

    if(n == 1){
        if(x[0]-'0' <= m){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
        return 0;
    }
    
    ll d = 0;
    rep(i, 0, n){
        chmax(d, x[i]-'0');
    }
    ll ok = 0, ng = INF;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        __int128_t tmp = 0, now = 1;
        bool f = true;
        rrep(i, n-1, 0){
            tmp += (__int128_t)now*(x[i]-'0');
            if(i == 0) break;
            if(now > m/mid){
                f = false;
                break;
            }else{
                now *= (__int128_t)mid;
            }
        }
        if(f && tmp <= (__int128_t)m) ok = mid;
        else ng = mid;
    }
    ok -= d;
    if(ok < 0) ok = 0;
    cout << ok << endl;
  


    return 0;
}