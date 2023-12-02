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
    ll n, l; cin >> n >> l;
    vector<ll> a(n);
    ll sum_a = 0;
    rep(i, 0, n){
        cin >> a[i];
        sum_a += a[i];
    }
    priority_queue<ll, vector<ll>, greater<ll>> que;
    rep(i, 0, n){
        que.push(a[i]);
    }
    if(l-sum_a > 0) que.push(l-sum_a);
    
    ll ans = 0;
    while(que.size() > 1){
        ll p = que.top(); que.pop();
        ll q = que.top(); que.pop();
        ans += p+q;
        que.push(p+q);
    }
    cout << ans << endl;
    return 0;
}