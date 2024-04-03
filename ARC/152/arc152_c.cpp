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
// https://atcoder.jp/contests/arc152/tasks/arc152_c

int main(){
    int n; cin >> n;
<<<<<<< HEAD
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int d = a[n-1]-a[0];
    int g = d;
    rep(i, 0, n) g = gcd(g, 2*(a[i]-a[0]));
    cout << a[0]%g+d << endl;
    
=======
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    while(true){
        ll mi = 0;
        rep(i, 0, n){
            if(2*a[i] < a[n-1]) continue;
            auto itr = upper_bound(a.begin(), a.end(), (2*a[i]+a[0])/2);
            if(itr == a.begin()) continue;
            --itr;
            if(2*(a[i]-*itr) == 0) continue;
            if(mi == 0){
                mi = 2*(a[i]-*itr);
            }
        }
        if(mi < 0){
            ll tmp = (a[0]+mi)/(3*(-mi))+1;
            rep(i, 0, n) a[i] += mi*tmp;
        }else break;
    }

    ll ans = a[n-1];
    rep(i, 0, n){
        if(2*a[i] < a[n-1]) continue;
        chmin(ans, 2*a[i]-a[0]);
    }
    cout << ans << endl;
>>>>>>> 478e5faf6d335dc5fcc07a937a798404ad74ad56
    return 0;
}