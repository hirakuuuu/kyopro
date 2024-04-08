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
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    auto f = [](ll x) -> ll {
        ll res = 0;
        while(x){
            res += x%10;
            x /= 10;
        }
        return res;
    };
    // map<ll, ll> m;
    // rep(i, 1, (1<<30)){
    //     if(i%5) continue;
    //     ll tmp = f(i), j = i;
    //     ll cnt = 0;
    //     rep(_, 0, 50){
    //         if(f(j) <= f(2*j)){
    //             break;
    //         }
    //         j *= 2;
    //         cnt++;
    //     }

    //     if(m.find(cnt) == m.end()){
    //         cout << i << ' ' << cnt;
    //         j = i;
    //         rep(_, 0, 50){
    //             cout << ' ' << f(j);
    //             if(f(j) <= f(2*j)){
    //                 break;
    //             }
    //             j *= 2;
    //         }
    //         cout << endl;
    //         m[cnt] = i;
    //     }
    // }
    // ll last = 30;
    // rep(i, 1, 20){
    //     ll tmp = last;
    //     cout << tmp << ' ';
    //     rep(j, 0, i) tmp /= 2;
    //     rep(j, 0, i+1){
    //         cout << f(tmp) << ' ';
    //         tmp *= 2;
    //     }
    //     cout << endl;
    //     last *= 10;
    // }
    ll a = 625;
    while(a){
        cout << a << ' ';
        if(f(a) <= f(2*a)) break;
        a *= 2;
    }
    cout << endl;
    return 0;
}