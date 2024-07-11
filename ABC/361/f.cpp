#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 0ならば素数, 0でないなら最小の素因数
vector<ll> erat(2000005);
void init_e(){
    rep(i, 2LL, (ll)sqrt(2000005)+1){
        if(erat[i] == 0){
            for(ll j = i*i; j < 2000005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}


int main(){
    ll n; cin >> n;
    vector<ll> p = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

    ll ans = 0;
    ll ok = -1, ng = IINF;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        if(mid*mid <= n) ok = mid;
        else ng = mid;
    }
    ans += ok;
    set<ll> s;
    rep(i, 2, 1000005){
        ll sq = (ll)sqrt(i);
        if(sq*sq == i || (sq+1)*(sq+1) == i) continue;
        ll tmp = i*i;
        rep(j, 3, 60){
            if(tmp > n/i) break;
            tmp *= i;  
            if(j%2 == 0) continue;
            s.insert(tmp);  
        }
    }
    ans += s.size();
    cout << ans << endl;
   


    
    return 0;
}