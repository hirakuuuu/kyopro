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
    int t; cin >> t;
    vector<ll> ans;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n+1), b(n+1);


        rep(i, 1, n+1){
            cin >> a[i];
            b[i] = b[i-1]^a[i];
        }

        if(b[n]){
            ans.push_back(0);
        }else{
            ll cnt = 0;
            rep(i, 1, n){
                if(b[i] == 0) cnt++;
            }
            ans.push_back(binpower(2, cnt));
        }
    }
    for(auto aa: ans){
        cout << aa << endl;
    }
    return 0;
}