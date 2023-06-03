#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc304/tasks/abc304_f

ll power(ll a, ll b, ll m=MOD){
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
    vector<int> yakusu;
    rep(i, 1, n){
        if(n%i == 0) yakusu.push_back(i);
    }

    map<int, ll> cnt;
    ll ans = 0;
    rep(i, 0, yakusu.size()){
        int m = yakusu[i];
        vector<bool> work(m, false);
        rep(j, 0, n){
            if(s[j] == '.') work[j%m] = true;
        }

        int sum = 0;
        rep(j, 0, m){
            if(work[j]){
                sum++;
            }
        }
        cnt[m] += power(2, m-sum);
        cnt[m] %= MOD;
        for(auto yy: yakusu){
            if(m < yy && yy%m == 0){
                cnt[yy] += MOD-cnt[m];
                cnt[yy] %= MOD;
            }
        }
    }

    for(auto y: yakusu){
        ans += cnt[y];
        ans %= MOD;
    }
    cout << ans << endl;
    
    return 0;
}