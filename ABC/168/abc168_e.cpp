#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;

constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc168/tasks/abc168_e

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return res;
}

int main(){
    int n; cin >> n;
    ll ans = 1, zero = 0, xzero = 0, yzero = 0;
    vector<ll> x(n), y(n);
    vector<pair<ll, ll>> X;
    rep(i, 0, n){
        cin >> x[i] >> y[i];
        if(y[i] < 0){
            x[i] = -x[i];
            y[i] = -y[i];
        }
        if(x[i] == 0 && y[i] == 0) zero++;
        else if(x[i] == 0) xzero++;
        else if(y[i] == 0) yzero++;
        else{
            ll tmp = gcd(abs(x[i]), y[i]);
            if(tmp > 0){
                x[i] /= tmp;
                y[i] /= tmp;
            }
            X.push_back({x[i], y[i]});
        }
    }


    ans *= power(2, xzero)+power(2, yzero)-1;
    map<pair<ll, ll>, ll> cnt;
    for(auto xx: X) cnt[xx]++;
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    reverse(X.begin(), X.end());

    for(auto xx: X){
        if(xx.first > 0 && cnt[{-xx.second, xx.first}] > 0){
            ans *= power(2, cnt[xx])+power(2, cnt[{-xx.second, xx.first}])-1;
            ans %= MOD;
        }else if(xx.first > 0 || cnt[{xx.second, -xx.first}] == 0){
            ans *= power(2, cnt[xx]);
            ans %= MOD;
        }
    }

    ans--;
    if(ans < 0) ans += MOD;
    cout << (ans+zero)%MOD << endl;
    
    return 0;
}