#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc173/tasks/abc173_e

ll bp(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b%2) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return res;
}


int main(){
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end(), [&](ll A, ll B) { return abs(A) > abs(B); });

    ll ans = 1, cnt = 0;
    rep(i, 0, k){
        ans *= a[i];
        ans %= MOD;
        if(a[i] < 0) cnt++;
    }

    if(ans != 0 and cnt%2){
        ll m1 = MOD, p1 = MOD;
        rep(i, 0, k){
            if(a[i] > 0) p1 = a[i];
        }
        rep(i, k, n){
            if(a[i] <= 0){
                m1 = a[i];
                break;
            }
        }
        bool ok1 = ((m1 != MOD) and (p1 != MOD));

        ll m2 = MOD, p2 = MOD;
        rep(i, 0, k){
            if(a[i] < 0) m2 = a[i];
        }
        rep(i, k, n){
            if(a[i] >= 0){
                p2 = a[i];
                break;
            }
        }
        bool ok2 = ((m2 != MOD) and (p2 != MOD));

        if(ok1 and ok2){
            if(m1*m2 >= p1*p2){
                ans = (((ans*m1)%MOD)*bp(p1, MOD-2))%MOD;
            }else{
                ans = (((ans*p2)%MOD)*bp(m2, MOD-2))%MOD;
            }
        }else if(ok1){
            ans = (((ans*m1)%MOD)*bp(p1, MOD-2))%MOD;
        }else if(ok2){
            ans = (((ans*p2)%MOD)*bp(m2, MOD-2))%MOD;
        }else{
            reverse(a.begin(), a.end());
            ans = 1;
            rep(i, 0, k){
                ans *= a[i];
                ans %= MOD;
            }
        }
    }
    cout << (ans+MOD)%MOD << endl;
    return 0;
}