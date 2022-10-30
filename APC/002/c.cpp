#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

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
    vector<int> p;
    rep(i, 2, 200005){
        bool f = true;
        for(auto pp: p){
            if(i%pp == 0){
                f = false;
                break;
            }
        }
        if(f) p.push_back(i);
    }
    vector<int> ans;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll a = binpower(2, n-1);
        

    }

    return 0;
}