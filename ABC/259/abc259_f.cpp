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
// https://atcoder.jp/contests/abc259/tasks/abc259_f

int main(){
    int n; cin >> n;
    vector<int> d(n);
    rep(i, 0, n) cin >> d[i];

    vector<int> u(n-1), v(n-1), w(n-1);
    priority_queue<tuple<int, int, int>> que;
    rep(i, 0, n-1){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
        que.push({w[i], u[i], v[i]});
    }

    vector<set<pair<int, int>>> s(n);
    ll ans = 0;
    while(!que.empty()){
        auto [W, U, V] = que.top(); que.pop();
        if(W <= 0) continue;

        if(d[U]-s[U].size() > 0 && d[V]-s[V].size() > 0){
            ans += W;
            s[U].insert({W, V});
            s[V].insert({W, U});
        }else{
            
        }

    }

    cout << ans << endl;
    
    return 0;
}