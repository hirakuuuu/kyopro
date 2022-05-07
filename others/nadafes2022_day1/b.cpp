#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_b

vector<ll> func(200005);
void func_init(int n){
    func[0] = func[1] = 1;
    rep(i, 2, n+1){
        func[i] = (func[i-1]*i)%mod;
    }
}

ll binpower(ll a, ll b){
    ll res = 1;
    while(b){
        if(b%2) res = (res*a)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return res;
}


int main(){
    ll n, k; cin >> n >> k;
    ll cnt = 0;
    rep(i, 1, n+1){
        if(i*2 > n) cnt++;
    }
    func_init(n);
    int ans = 0;
    if(cnt <= k){
        ll N = n-cnt, K = k-cnt;
        ans = (((func[N]*binpower(func[N-K], mod-2))%mod)*binpower(func[K], mod-2))%mod;
    }
    cout << ans << endl;
    
    return 0;
}