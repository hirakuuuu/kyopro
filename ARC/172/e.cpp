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

/*
答えは一意になるという予想はできた
10^2, 10^3, ... , 10^9 で一意になることが分からなかった
X を 10^2 でわったあまりから下二桁が定まる
10^3 でわったあまりは下二桁が定まっていることから，候補が10通りに絞れる
同様に，10^4, 10^5, ... , 10^9 まで10通り計算すれば答えが分かる

*/

ll power(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){

    ll m = (1e9);
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        int ans = -1;
        for(int i = 1; i < 100; i++){
            if(power(i, i, 100) == x%100){
                ans = i;
                break;
            }
        }
        
        int t = 100;
        for(int i = 3; i <= 9; i++){
            rep(k, 0, 10){
                int tmp = ans+t*k;
                if(power(tmp, tmp, t*10) == x%(t*10)){
                    ans += t*k;
                    break;
                }
            }
            t *= 10;
        }
        cout << ans << endl;
    }   

    return 0;
}