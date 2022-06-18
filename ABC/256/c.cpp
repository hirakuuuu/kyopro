#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc256/tasks/abc256_c

int main(){
    vector<int> h(3), w(3);
    rep(i, 0, 3) cin >> h[i];
    rep(i, 0, 3) cin >> w[i];
    
    ll ans = 0;

    rep(i, 1, 31){
        rep(j, 1, 31){
            rep(k, 1, 31){
                rep(l, 1, 31){
                    int sl = 0, sb = 0, lb = 0;
                    //h[0] = i+j+?
                    if(i+j >= h[0]) continue;
                    sl += h[0]-(i+j);

                    // h[1] = k+l+?
                    if(k+l >= h[1]) continue;
                    sl += h[1]-(k+l);

                    if(sl >= w[2]) continue;
                    lb = w[2]-sl;
                    
                    // w[0] = i+k+?
                    if(i+k >= w[0]) continue;
                    sb += w[0]-(i+k);

                    // w[1] = j+l+?
                    if(j+l >= w[1]) continue;
                    sb += w[1]-(j+l);

                    if(h[2]-sb == lb) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}