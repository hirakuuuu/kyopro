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
// 

int main(){
    ll n; cin >> n;
    vector<ll> o;
    ll m = n;
    while(m){
        o.push_back(m%10);
        m /= 10;
    }
    m = o.size();
    ll ans = 0;
    rep(i, 1, (1<<m)-1){
        vector<vector<ll>> cnt(2, vector<ll>(10));
        rep(j, 0, m){
            cnt[((i>>j)&1)][o[j]]++;
        }
        vector<ll> a(2);
        rep(j, 0, 2){
            rrep(k, 9, 0){
                rep(l, 0, cnt[j][k]){
                    a[j] = a[j]*10+k;
                }
            }
        }
        chmax(ans, a[0]*a[1]);
    }
    cout << ans << endl;
    return 0;
}