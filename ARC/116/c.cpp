#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc116/tasks/arc116_c

vector<ll> func(300005), invf(300005);

ll binpower(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b%2) res = (res*a)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return res;
}

void func_init(){
    func[0] = func[1] = 1;
    rep(i, 2, 300005){
        func[i] = (func[i-1]*i)%mod;
    }

    invf[300004] = binpower(func[300004], mod-2);
    for (int i=300003; i>=0; i--) invf[i] = invf[i+1] * (i+1) % mod;
}

ll nck(ll n, ll k){
    return func[n]*(invf[n-k]%mod*invf[k]%mod)%mod;
}

vector<ll> p(300005);
void erat(){
    rep(i, 2, 300005){
        if(p[i]) continue;
        p[i] = i;
        for(ll j = i+i; j < 300005; j += i){
            if(p[j]) continue;
            p[j] = i;
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    func_init();
    erat();
    ll ans = 1;
    rep(i, 2, m+1){
        ll j = i, cnt = 1;
        while(p[j]){
            ll k = p[j], a = 0;
            while(j%k == 0){
                a++;
                j /= k;
            }
            cnt = cnt*nck(a+n-1, a)%mod;
        }
        ans = (ans+cnt)%mod;
        //cout << ans << endl;
    }
    cout << ans << endl;    
    return 0;
}