#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_at

vector<ll> a(46), b(46), c(46);

int main(){
    int n; cin >> n;
    rep(i, 0, n){
        int A; cin >> A;
        a[A%46]++;
    }
    rep(i, 0, n){
        int B; cin >> B;
        b[B%46]++;
    }
    rep(i, 0, n){
        int C; cin >> C;
        c[C%46]++;
    }

    ll ans = 0;
    rep(i, 0, 46){
        rep(j, 0, 46){
            rep(k, 0, 46){
                if((i+j+k)%46) continue;
                ans += a[i]*b[j]*c[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}