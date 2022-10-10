#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc047/tasks/agc047_a

int main(){
    int n; cin >> n;
    vector<double> a(n);
    map<pll, ll> cnt;
    rep(i, 0, n){
        cin >> a[i];
    }
    rep(i, 0, n){
        ll b = llround(a[i]*(1e9));
        ll two = 0, five = 0;
        while(b%2 == 0 or b%5 == 0){
            if(b%2 == 0){
                two++;
                b /= 2;
            }
            if(b%5 == 0){
                five++;
                b /= 5;
            }
        }
        cnt[{two, five}]++;
    }
    ll ans = 0;

    for(auto p1: cnt){
        for(auto p2: cnt){
            if(p1.first.first+p2.first.first >= 18 and p1.first.second+p2.first.second >= 18){
                if(p1 <p2){
                    ans += p1.second*p2.second;
                }else if(p1 == p2){
                    ans += (p1.second)*(p1.second-1)/2;
                }

            }
        }
    }
    cout << ans << endl;
    return 0;
}