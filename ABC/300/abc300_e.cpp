#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc300/tasks/abc300_e

vector<int> p={2, 3, 5};
// 繰り返し二乗法
ll power(ll a, ll b, ll m=998244353){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}


int main(){
    ll n; cin >> n;
    ll tmp = n;

    vector<int> cnt(3);
    rep(i, 0, 3){
        while(tmp%p[i] == 0){
            tmp /= p[i];
            cnt[i]++;
        }
    }

    if(tmp != 1){
        cout << 0 << endl;
        return 0;
    }

    vector<ll> yakusu;
    ll tmp1 = 1, tmp2 = 1, tmp3 = 1;
    rep(i, 0, cnt[0]+1){
        tmp2 = 1;
        rep(j, 0, cnt[1]+1){
            tmp3 = 1;
            rep(k, 0, cnt[2]+1){
                yakusu.push_back(tmp1*tmp2*tmp3);
                tmp3 *= 5;
            }
            tmp2 *= 3;
        }
        tmp1 *= 2;
    }

    sort(yakusu.begin(), yakusu.end());

    map<ll, int> m;
    rep(i, 0, yakusu.size()) m[yakusu[i]] = i+1;

    vector<ll> dp(yakusu.size()+1);
    dp[1] = 1;
    rep(i, 1, yakusu.size()){
        rep(j, 2, 7){
            if(m[yakusu[i-1]*j] == 0) continue;
            dp[m[yakusu[i-1]*j]] += dp[i]*power(5, mod-2);
            dp[m[yakusu[i-1]*j]] %= mod;
        }
    }
    cout << dp[m[n]] << endl;

    return 0;
}