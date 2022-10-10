#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc124/tasks/arc124_c

int main(){
    ll n; cin >> n;
    vector<ll> a(n+1), b(n+1);
    rep(i, 1, n+1) cin >> a[i] >> b[i];

    vector<vector<ll>> yakusu(2);
    for(int i = 1; i*i <= a[1]; i++){
        if(a[1]%i == 0){
            yakusu[0].push_back(i);
            if(a[1]/i != i) yakusu[0].push_back(a[1]/i);
        }
    }
    for(int i = 1; i*i <= b[1]; i++){
        if(b[1]%i == 0){
            yakusu[1].push_back(i);
            if(b[1]/i != i) yakusu[1].push_back(b[1]/i);
        }
    }

    ll ans = 1;

    for(auto y1: yakusu[0]){
        for(auto y2: yakusu[1]){
            bool f = true;
            rep(i, 2, n+1){
                f &= (a[i]%y1 == 0 and b[i]%y2 == 0) or (a[i]%y2 == 0 and b[i]%y1 == 0);
            }
            if(f) ans = max(ans, lcm(y1, y2));
        }
    }

    cout << ans << endl;

    
    return 0;
}