#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc293/tasks/abc293_f

/*
3乗以上は10＾6くらいしかないから全探索できる
2乗は2次方程式？

b > 1000 とかで考えれば、ビットとしてあり得る文字列はそんなに多くない（2＾6程度）
二分探できるね

*/

// int main(){
//     int t; cin >> t;
//     while(t--){
//         ll n; cin >> n;
//         if(n == 2){
//             cout << 1 << endl;
//             continue;
//         }

//         set<ll> s;
//         s.insert(n);
//         s.insert(n-1);
//         // 3乗以上
//         rep(i, 2, cbrt(n)+1){
//             if(i >= n-1) break;
//             if(i == n || i == n-1) continue;
//             ll m = n;
//             while(m > 0 && (m%i == 1 || m%i == 0)){
//                 if(m%i == 1) m--;
//                 m /= i;
//             }
//             if(!m) s.insert(i);
//         }
//         // x*x=n
//         ll x = (ll)sqrt(n);
//         if(x >= 2 && x*x == n) s.insert(x);
//         // x*x = n-1
//         x = (ll)sqrt(n-1);
//         if(x >= 2 && x*x == n-1) s.insert(x);
//         // x*x+x=n
//         double y = (-1.0+sqrt(1.0+4.0*(double)(n)))/2.0;
//         x = (ll)y;
//         if(x >= 2 && x*x+x == n) s.insert(x);
//         // x*x+x=n-1
//         y = (-1.0+sqrt(1.0+4.0*(double)(n-1)))/2.0;
//         x = (ll)y;
//         if(x >= 2 && x*x+x == n-1) s.insert(x);
        


//         cout << s.size() << endl;
//     }
    
//     return 0;
// }

int main(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n == 2){
            cout << 1 << endl;
            continue;
        }
        set<ll> s;
        s.insert(n);
        s.insert(n-1);
        rep(i, 3, 65){
            ll l = 1, r = 1e18+1;
            while(r-l > 1){
                ll m = (l+r)/2, tmp = n;
                rep(j, 0, i-1){
                    tmp /= m;
                }
                if(tmp) l = m;
                else r = m;
            }
            if(l >= 2){
                ll m = n;
                while(m > 0 && (m%l == 1 || m%l == 0)){
                    if(m%l == 1) m--;
                    m /= l;
                }
                if(!m) s.insert(l);
            }
        }
        cout << s.size() << endl;
    }
}