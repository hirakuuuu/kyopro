#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    vector<ll> a(n), b(n), c(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i] >> c[i];
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    queue<pair<ll, ll>> que;
    rep(i, 0, n){
        que.push({a[i], i});
    }
    vector<ll> ans(n);
    ll sum = 0;
    ll time = 0;
    rep(i, 0, n){
        auto [A, id] = que.front(); que.pop();
        chmax(time, A);
        while(!pq.empty() && sum+c[id] > k){
            // cout << pq.top().first << ' ' << pq.top().second << endl;
            chmax(time, pq.top().first);
            sum -= pq.top().second;
            pq.pop();
        }
        ans[id] = time;
        pq.push({time+b[id], c[id]});
        sum += c[id];
    }
    rep(i, 0, n){
        cout << ans[i] << endl;
    }

    return 0;
}