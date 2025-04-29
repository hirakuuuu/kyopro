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
    int t; cin >> t;
    while(t--){
        vector<ll> a(6), b(6);
        rep(i, 1, 6) cin >> a[i];
        rep(i, 1, 6) cin >> b[i];

        ll cap = 0, tot = 0;
        rep(i, 1, 6) cap += b[i]*i;
        rep(i, 1, 6) tot += a[i]*i;
        if(tot > cap){
            cout << "No" << endl;
            continue;
        }

        // w = 5
        if(a[5] > b[5]){
            cout << "No" << endl;
            continue;
        }
        b[5] -= a[5];
        a[5] = 0;

        // w = 4
        if(a[4] > b[5]+b[4]){
            cout << "No" << endl;
            continue;
        }
        if(a[4] <= b[4]){
            b[4] -= a[4];
            a[4] = 0;
        }else{
            a[4] -= b[4];
            b[4] = 0;
            b[5] -= a[4];
            b[1] += a[4]; // 1 を持てる人が増える
            a[4] = 0;
        }

        // w = 3
        if(a[3] > b[5]+b[4]+b[3]){
            cout << "No" << endl;
            continue;
        }
        if(a[3] <= b[3]){
            b[3] -= a[3];
            a[3] = 0;
        }else if(a[3] <= b[3]+b[5]){
            a[3] -= b[3];
            b[3] = 0;
            b[5] -= a[3];
            b[2] += a[3];
            a[3] = 0;
        }else{
            a[3] -= b[3];
            b[3] = 0;
            a[3] -= b[5];
            b[2] += b[5];
            b[5] = 0;
            b[4] -= a[3];
            b[1] += a[3];
            a[3] = 0;
        }

        // w = 2
        if(a[2] > b[5]*2+b[4]*2+b[3]+b[2]){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}