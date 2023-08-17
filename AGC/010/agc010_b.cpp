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
// https://atcoder.jp/contests/agc010/tasks/agc010_b

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll sum = 0;
    rep(i, 0, n) sum += a[i];
    ll ope = n*(n+1)/2;
    if(sum%ope != 0){
        cout << "NO" << endl;
        return 0; 
    }

    ll cnt = sum/ope;
    ll need = 0;
    vector<ll> b(n);
    rep(i, 0, n) b[i] = a[i]-a[(i+1)%n];
    rep(i, 0, n){
        ll tmp = b[i]+cnt;
        if(tmp < 0 || tmp%n != 0){
            cout << "NO" << endl;
            return 0;
        }
        need += tmp/n;
    }

    if(need == cnt) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}