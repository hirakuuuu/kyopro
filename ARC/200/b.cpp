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

    ll tmp = 3;
    vector<ll> num(18);
    num[0] = 1;
    rep(i, 1, 18){
        num[i] = tmp;
        while(to_string(tmp).size() <= i+1){
            tmp *= 3;
        }
        tmp /= 3;
    }
    vector<ll> ten(18);
    ten[0] = 1;
    rep(i, 1, 18) ten[i] = ten[i-1]*10;

    int t; cin >> t;
    while(t--){
        vector<ll> a(3);
        vector<ll> x(2);
        rep(i, 0, 3){
            cin >> a[i];
        }
        if(a[2] < max(a[0], a[1]) || a[0]+a[1] < a[2]){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
            if(a[0] > a[1]){
                if(a[0]-(a[2]-a[1]) == 0){
                    x[0] = num[a[0]];
                    x[1] = num[a[1]-(a[2]-a[0])]*ten[a[2]-a[0]];
                    x[1] -= 2;
                }else{
                    x[0] = num[a[0]];
                    x[1] = num[a[1]-(a[2]-a[0])]*ten[a[2]-a[0]];
                }
            }else{
                if(a[0]-(a[2]-a[1]) == 0){
                    x[1] = num[a[1]];
                    x[0] = num[a[0]-(a[2]-a[1])]*ten[a[2]-a[1]];
                    x[0] -= 2;
                }else{
                    x[1] = num[a[1]];
                    x[0] = num[a[0]-(a[2]-a[1])]*ten[a[2]-a[1]];
                }
            }
            cout << x[0] << ' ' << x[1] << endl;

            assert(to_string(x[0]).size() == a[0]);
            assert(to_string(x[1]).size() == a[1]);
            assert(to_string(lcm(x[0], x[1])).size() == a[2]);
        }

    }
    return 0;
}