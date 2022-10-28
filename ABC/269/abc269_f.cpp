#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc269/tasks/abc269_f

int main(){
    ll n, m; cin >> n >> m;
    int q; cin >> q;
    vector<ll> A(q), B(q), C(q), D(q);
    rep(i, 0, q) cin >> A[i] >> B[i] >> C[i] >> D[i];
    rep(i, 0, q){
        ll a = A[i], b = B[i], c = C[i], d = D[i];
        ll total = 0;

        // 行の値
        ll o1 = 0, e1 = 0;
        ll l = 0, cnt = 0;
        // 奇数行
        if(c%2 + d%2 == 0) cnt = (d-c)/2;
        else cnt = (d-c)/2+1;
        if(c%2 == 0) l = c+1;
        else l = c;
        cnt %= mod;
        l %= mod;
        o1 = (cnt*(l+cnt-1))%mod;


        // 偶数行
        if(c%2 + d%2 == 2) cnt = (d-c)/2;
        else cnt = (d-c)/2+1;
        if(c%2 == 1) l = c+1;
        else l = c;
        cnt %= mod;
        l %= mod;
        e1 = (cnt*(l+(cnt-1)))%mod;

        if(a%2 + b%2 == 2) total = (((b-a)/2+1)*o1+((b-a)/2)*e1)%mod;
        else if(a%2+b%2 == 1) total = (((b-a)/2+1)*o1+((b-a)/2+1)*e1)%mod;
        else total = (((b-a)/2)*o1+((b-a)/2+1)*e1)%mod;

        // もう1つの方
        ll o2 = 0, e2 = 0;
        ll gap = 0;
        if(a%2+b%2 == 0) cnt = ((b-a)/2)%mod;
        else cnt = ((b-a)/2+1)%mod;
        // 奇数行
        if(c%2+d%2 == 0){
            gap = m*((d-c)/2)%mod;
            if(a%2 == 0) l = (a*gap)%mod;
            else l = ((a-1)*gap)%mod;
        }else{
            gap = m*((d-c)/2+1)%mod;
            if(a%2 == 0) l = (a*gap)%mod;
            else l = ((a-1)*gap)%mod;
        }
        o2 = (cnt*(l+(cnt-1)*gap%mod))%mod;

        if(a%2+b%2 == 2) cnt = ((b-a)/2)%mod;
        else cnt = ((b-a)/2+1)%mod;
        // 偶数行
        if(c%2+d%2 == 2){
            gap = m*((d-c)/2)%mod;
            if(a%2 == 1) l = (a*gap)%mod;
            else l = ((a-1)*gap)%mod;
        }else{
            gap = m*((d-c)/2+1)%mod;
            if(a%2 == 1) l = (a*gap)%mod;
            else l = ((a-1)*gap)%mod;
        }
        e2 = (cnt*(l+(cnt-1)*gap%mod))%mod;


        total += o2;
        total += e2;
        total %= mod;

        cout << total << "\n";

    }
    
    return 0;
}