#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc249/tasks/abc249_a

int main(){
    int a, b, c, d, e, f, x; cin >> a >> b >> c >> d >> e >> f >> x;
    int taka = x/(a+c)*a*b+min(a, x%(a+c))*b;
    int aoki = x/(d+f)*d*e+min(d, x%(d+f))*e;
    if(taka > aoki) cout << "Takahashi" << endl;
    else if(taka < aoki) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
    
    return 0;
}