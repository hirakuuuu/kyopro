#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


// int main(){
//     int n, c; cin >> n >> c;
//     vector<vector<int>> over(c, vector<int>(100005));
//     rep(i, 0, n){
//         int s, t, C; cin >> s >> t >> C;
//         rep(j, s, t+1) over[C-1][j] = 1;
//     }

//     vector<int> over_wa(100001);
//     rep(i, 1, 100001){
//         rep(j, 0, c) over_wa[i] += over[j][i-1];
//     }
//     int ans = 0;
//     rep(i, 0, 100001) ans = max(ans, over_wa[i]);

//     cout << ans << endl;
  
// }

int main(){
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end(), [&](ll b, ll c){ return abs(b) > abs(c); });
    ll ans = 1, cnt = 0;
    rep(i, 0, k){
        if(a[i] < 0){
            cnt++;
        }
        ans = (ans*a[i])%MOD;
    }
    if(cnt%2){
        ll p1 = MOD, m1 = MOD, p2 = MOD, m2 = MOD;
        rep(i, 0, k) if(a[i] < 0) m1 = a[i];
        rep(i, k, n){
            if(a[i] >= 0){
                p1 = a[i];
                break;
            }
        }
        bool ok1 = ((p1 != MOD) and (m1 != MOD));

        rep(i, 0, k) if(a[i] > 0) p2 = a[i];
        rep(i, k, n){
            if(a[i] <= 0){
                m2 = a[i];
                break;
            }
        }
        bool ok2 = ((p2 != MOD) and (m2 != MOD));

        if(ok1 and ok2){
            if(1LL*p1*p2 > 1LL*m1*m2) ans = ans*p1/m1;
            else ans = ans*m2/p2;
        }else if(ok1) ans = ans*p1/m1;
        else if(ok2) ans = ans*m2/p2;
        else{
            sort(a.begin(), a.end(), greater<ll>());
            ans = 1;
            rep(i, 0, k) ans = (ans*a[i])%MOD;
        }
    }

    cout << (ans%MOD+MOD)%MOD << endl;
}