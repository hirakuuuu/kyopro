#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007

const ll mod = 998244353;
map<ll, ll> m;
ll f(ll x){
    if(m[x]) return m[x];
    if(x <= 4) return x;
    return m[x] = (f(x/2+x%2)*f(x/2))%mod;
}

int main(){
    ll x; cin >> x;
    cout << f(x) << endl;
}


