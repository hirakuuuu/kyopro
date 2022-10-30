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
        ll a = 0;
        int n; cin >> n;
        string s; cin >> s;
        // 前半部分の文字数
        int b = n/2+n%2;
        rep(i, 0, b){
            // i-1文字目までｓと一致していて、i文字目でｓより辞書順で前に来るようになる回文の総数
            // i文字目まででｓより前に来ることが確定しているので、前半部分の残り文字数は好きに決められる
            a = (a+(s[i]-'A')*binpower(26, b-i-1))%mod;
            // 前半部分がｓと一致している場合、その回文をカウントするべきかどうか
            // →前半部分がｓと一致しているような回文が辞書順でｓより前に来るかどうかを判定
            if(i == b-1){
                int length;
                if(n%2)length = b-1;
                else length = b;
                string ss = s.substr(0, length);
                reverse(ss.begin(), ss.end());
                // 条件を満たすならカウント
                if(ss <= s.substr(n/2+n%2, length)) a++;
            }
        }
        ans.push_back(a%mod);
    }
    for(auto aa: ans){
        cout << aa << endl;
    }
  
}