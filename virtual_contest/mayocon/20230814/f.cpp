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

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    priority_queue<ll, vector<ll>, greater<ll>> que;
    rep(i, 0, k) que.push(a[i]);
    sort(a.begin(), a.end());
    rep(i, 0, n-k){
        ll q = que.top(); que.pop();
        que.push(q+a[i]);
    }

    cout << que.top() << endl;



    
    return 0;
}