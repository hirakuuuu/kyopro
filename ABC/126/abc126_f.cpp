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

/*
k = 0 は明らか（２つずつ並べていくだけ）
また、k >= 2^m のときは -1
m = 0 のとき、k = 0 のときは 0 0, それ以外 -1
m = 1 のとき、k = 0 のときは 0 0 1 1, それ以外 -1
m >= 2 のとき、0 xor 1 xor ... xor 2^{m}-1 = 0
よって、m=2, k = 3 ならば、 2 1 0 3 0 1 2 3 と並べればよい
*/

int main(){
    int m, k; cin >> m >> k;
    if(k >= 1<<m){
        cout << -1 << endl;
    }else{
        if(m == 0){
            if(k == 0) cout << "0 0" << endl;
            else cout << -1 << endl;
        }else if(m == 1){
            if(k == 0) cout << "0 0 1 1" << endl;
            else cout << -1 << endl;
        }else{

            rrep(i, (1<<m)-1, 0){
                if(i == k) continue;
                cout << i << ' ';
            }
            cout << k << ' ';
            rep(i, 0, 1<<m){
                if(i == k) continue;
                cout << i << ' ';
            }
            cout << k << endl;
        }
    }



    return 0;
}