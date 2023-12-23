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
// https://atcoder.jp/contests/abc334/tasks/abc334_c

int main(){
    int n, k; cin >> n >> k;
    ll ans = IINF;
    vector<int> a(k);
    rep(i, 0, k) cin >> a[i];
    vector<int> gap(k-1);
    rep(i, 0, k-1) gap[i] = a[i+1]-a[i];

    if(k%2 == 0){
        int sum = 0;
        rep(i, 0, k/2){
            sum += a[2*i+1]-a[2*i];
        }
        ans = sum;
    }else{
        int R = 0;
        rrep(i, k-1, 1){
            if(i%2 == 0) R += a[i]-a[i-1];
        }
        ans = R;
        rep(i, 1, k){
            if(i%2 == 1){
                R -= a[i+1]-a[i];
                R += a[i+1]-a[i-1];
            }else{
                R -= a[i]-a[i-2];
                R += a[i-1]-a[i-2];
            }
            chmin(ans, R);
        }
    }

    cout << ans << endl;
    
    return 0;
}