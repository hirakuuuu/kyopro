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
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n == 2){
            cout << "P" << endl;
            continue;
        }

        ll total = 1, tmp = 2;
        bool f = false;
        while(1 <= n/tmp){
            total = lcm(total, tmp);
            if(n%total){
                if(gcd(n, tmp) != 1) cout << "P" << endl;
                else cout << "K" << endl;
                f = true;
                break;
            }
            tmp++;
        }
        if(f) continue;
        cout << "K" << endl;
        
    }
    return 0;
}