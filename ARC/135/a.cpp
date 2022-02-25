#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007

const ll mod = 998244353;

ll binpower(ll a, ll b) {
	ll ans = 1;
	while (b != 0) {
		if (b % 2 == 1) {
			ans = (ans*a) % mod;
		}
		a = (a*a) % mod;
		b /= 2;
	}
	return ans;
}

int main(){
    ll x; cin >> x;
    ll cpx = x, a = 1;

    // ここをlogで書いてたからできなかった
    while(cpx > 1){
      a *= 2;
      cpx /= 2;
    }
    ll b = a/2, ans = 1;
    
    if(x <= a+b){
        ans = binpower(2, a+b-x)*binpower(3, x-a);
    }else{
        ans = binpower(3, 2*a-x)*binpower(4, x-a-b);
    }
    cout << ans%mod << endl;
}
