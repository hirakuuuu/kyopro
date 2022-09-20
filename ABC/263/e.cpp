#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc263/tasks/abc263_e

// aをbで割った
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
    ll n; cin >> n;
    vector<ll> a(n-1);
    rep(i, 0, n-1){
        cin >> a[i];
    }

    vector<ll> e(n), move(n);
    rep(i, 0, n-1){
        e[i] = binpower(a[i], mod-2);
    }

    rep(i, 0, n-1){
        move[i+1] += (binpower(a[i]+1, mod-2)*(move[i]+e[i]+1))%mod;
        move[i+1] %= mod;

        if(i+a[i]+1 < n){
            move[i+a[i]+1] -= (binpower(a[i]+1, mod-2)*(move[i]+e[i]+1))%mod-mod;
            move[i+a[i]+1] %=mod;
        }
    }

    rep(i, 1, n){
        move[i] += move[i-1];
        move[i] %= mod;
    }

    rep(i, 0, n){
        cout << (move[i]+e[i])%mod << endl;
    }

    
    return 0;
}