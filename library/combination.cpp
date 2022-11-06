#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// パスカルの三角形の要領で再帰的に求められる
ll c[100][100];

ll combination(ll n, ll k){
    if(c[n][k] > 0) return c[n][k];
    if(k == 0 or n == k) return c[n][k] = 1;
    return c[n][k] = combination(n-1, k)+combination(n-1, k-1);
}

int main(){

    return 0;
}