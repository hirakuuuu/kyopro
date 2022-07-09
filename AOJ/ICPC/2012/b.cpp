#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://onlinejudge.u-aizu.ac.jp/problems/1180

int main(){
    while(true){
        ll a, l; cin >> a >> l;
        if(a*a+l*l == 0) break;
        map<ll, ll> m;
        m[a] = 1;
        ll cnt = 2;
        vector<ll> b(l);
        rep(i, 0, l){
            b[i] = a%10;
            a /= 10;
        }
        while(true){
            sort(b.begin(), b.end());
            ll max_b = 0, o = 1;
            rep(i, 0, l){
                max_b += b[i]*o;
                o *= 10;
            }
            o = 1;
            reverse(b.begin(), b.end());
            ll min_b = 0;
            rep(i, 0, l){
                min_b += b[i]*o;
                o *= 10;
            }
            ll new_b = max_b - min_b;
            if(m[new_b]){
                printf("%lld %lld %lld\n", m[new_b]-1, new_b, cnt-m[new_b]);
                break;
            }else{
                m[new_b] = cnt;
                cnt++;
            }
            rep(i, 0, l){
                b[i] = new_b%10;
                new_b /= 10;
            }
        }





    }
    
    return 0;
}