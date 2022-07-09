#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc258/tasks/abc258_b

int main(){
    int n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, n){
            a[i][j] = s[j]-'0';
        }
    }

    vector<ll> dh = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<ll> dw = {-1, 0, 1, -1, 1, -1, 0, 1};
    ll ans = 0;

    rep(i, 0, n){
        rep(j, 0, n){
            ll max_cnt = 0;
            rep(k, 0, 8){
                ll cnt = a[i][j];
                int ni = i, nj = j;
                rep(l, 0, n-1){
                    cnt *= 10;
                    ni = (ni+dh[k]+n)%n;
                    nj = (nj+dw[k]+n)%n;
                    cnt += a[ni][nj];
                }
                max_cnt = max(max_cnt, cnt);
            }
            ans = max(ans, max_cnt);
        }
    }
    cout << ans << endl;
    
    return 0;
}