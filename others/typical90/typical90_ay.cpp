#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_ay

int main(){
    ll n, k, p; cin >> n >> k >> p;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<ll>> price(21);
    rep(i, 0, 1<<20){
        ll total = 0, i2 = i, cnt = 0;
        bool f = true;
        rep(j, 0, 20){
            if(j < n and i2&(1<<j)){
                total += a[j];
                cnt++;
            }else if(i2&(1<<j)){
                f = false;
                break;
            }
        }
        if(f) price[cnt].push_back(total);
    }

    rep(i, 0, 21){
        sort(price[i].begin(), price[i].end());
    }

    ll ans = 0;

    rep(i, 0, 1<<20){
        ll total = 0, i2 = i, cnt = 0;
        bool f = true;
        rep(j, 0, 20){
            if(20+j < n and i2&(1<<j)){
                total += a[j+20];
                cnt++;
            }else if(i2&(1<<j)){
                f = false;
                break;
            }
        }

        if(f and cnt <= k and k-cnt <= 20){
            int pos = upper_bound(price[k-cnt].begin(), price[k-cnt].end(), p-total)-price[k-cnt].begin();
            ans += pos;
        }
    }

    cout << ans << endl;








    
    return 0;
}