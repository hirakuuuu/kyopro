#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_r

/*
俯角の計算　→　三角関数とその逆関数
・弧度法と度数法の違いに注意
*/

const double pi = 3.14159265358979;

int main(){
    int t; cin >> t;
    double l, x, y; cin >> l >> x >> y;
    int q; cin >> q;

    while(q--){
        double e; cin >> e;
        double cy = -l*sin(2*pi*e/t)/2, cz = l*(1-cos(2*pi*e/t))/2;
        double cos_fukaku = sqrt(x*x+(y-cy)*(y-cy))/sqrt(x*x+(y-cy)*(y-cy)+cz*cz);
        printf("%.12f\n", acos(cos_fukaku)*180/pi);

    }
    
    return 0;
}