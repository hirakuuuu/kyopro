#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_o

/*
調和級数はO(nlogn)
・最小の差がｋになるようにボールをａ個選ぶ選び方を考えると良い
*/

ll bp(ll a, ll b){
    ll res = 1;
    while(b){
        if(b%2) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return res;
}

ll func[100005];
void func_init(){
    func[0] = func[1] = 1;
    rep(i, 2, 100005){
        func[i] = func[i-1]*i;
        func[i] %= MOD;
    }
}

ll nCk(ll n, ll k){
    ll res = (func[n]*bp(func[n-k], MOD-2))%MOD;
    return (res*bp(func[k], MOD-2))%MOD;
}

int main(){
    ll n; cin >> n;
    func_init();

    ll ans = 0, a = 0;
    rep(k, 1, n+1){
        ans = 0, a = 1;
        while(n-(a-1)*(k-1) >= a){
            ans += nCk(n-(a-1)*(k-1), a);
            a++;
        }
        cout << ans%MOD << endl;
    }

    
    return 0;
}