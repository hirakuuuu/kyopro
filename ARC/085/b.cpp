#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc078/tasks/arc085_b

int n, z, w, a[2005], memo[2][2005];

int f(int i, int turn, int X, int Y){
    if(i == n) return abs(X-Y);

    if(memo[turn][i] >= 0) return memo[turn][i];

    if(!turn){
        int ma = -1;
        rep(j, i, n){
            ma = max(ma, f(j+1, 1-turn, a[j], Y));
        }
        return memo[turn][i] = ma;
    }else{
        int mi = 1000000007;
        rep(j, i, n){
            mi = min(mi, f(j+1, 1-turn, X, a[j]));
        }
        return memo[turn][i] = mi;
    }
}

int main(){
    cin >> n >> z >> w;
    rep(i, 0, n) cin >> a[i];

    rep(i, 0, 2){
        rep(j, 0, 2005){
            memo[i][j] = -1;
        }
    }
    cout << f(0, 0, z, w) << endl;
    
    return 0;
}