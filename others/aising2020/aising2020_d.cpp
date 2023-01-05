#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/aising2020/tasks/aising2020_d

// 2新表記したときの1の個数を求める関数
ll popcount(ll n){
    ll res = 0;
    while(n > 0){
        res += n%2;
        n /= 2;
    }
    return res;
}

// n%popcount(n) = 0となる操作回数
ll f(ll n){
    if(n == 0) return 0;
    ll tmp = n%popcount(n);
    return f(tmp)+1;
}

ll power(ll a, ll b, ll m=mod){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    rep(i, 0, n){
        cnt += s[i]=='1' ? 1 : 0;
    }

    // cnt+1で割った余り
    ll tmp1 = 0;
    rep(i, 0, n){
        tmp1 *= 2;
        tmp1 += s[i]=='1' ? 1 : 0;
        tmp1 %= cnt+1;
    }
    // cnt-1で割った余り
    ll tmp2 = 0;
    if(cnt >= 2){
        rep(i, 0, n){
            tmp2 *= 2;
            tmp2 += s[i]=='1' ? 1 : 0;
            tmp2 %= cnt-1;
        }
    }

    rep(i, 0, n){
        if(s[i] == '0'){
            ll ans = (tmp1+power(2, n-i-1, cnt+1))%(cnt+1);
            cout << 1+f(ans) << endl;
        }else{
            if(cnt == 1){
                cout << 0 << endl;
            }else{
                ll ans = (tmp2-power(2, n-i-1, cnt-1))%(cnt-1);
                if(ans < 0) ans += (cnt-1);
                cout << 1+f(ans) << endl;
            }
        }
    }
    
    return 0;
}