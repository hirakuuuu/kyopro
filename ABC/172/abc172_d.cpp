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
// https://atcoder.jp/contests/abc172/tasks/abc172_d

// 最小の素因数
vector<ll> erat(10000005);
void init_e(){
    rep(i, 2, sqrt(10000005)){
        if(erat[i] == 0){
            erat[i] = i;
            for(ll j = i*i; j < 10000005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }

    rep(i, 2, 10000005){
        if(erat[i] == 0) erat[i] = i;
    }
}

int main(){
    init_e();
    ll n; cin >> n;
    ll ans = 0;
    rep(i, 1, n+1){
        ll cnt = 1, tmp = i;
        while(tmp != 1){
            ll p = 1;
            while(erat[tmp] == erat[tmp/erat[tmp]]){
                p++;
                tmp /= erat[tmp];
            }
            tmp /= erat[tmp];
            cnt *= p+1;
        }
        ans += i*cnt;
    }
    cout << ans << endl;
    return 0;
}