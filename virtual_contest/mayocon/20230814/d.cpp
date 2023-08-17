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
    int n, m; cin >> n >> m;
    priority_queue<int> que;
    rep(i, 0, n){
        int a; cin >> a;
        que.push(a);
    }

    while(m--){
        int q = que.top(); que.pop();
        que.push(q/2);
    }

    ll ans = 0;
    while(!que.empty()){
        ans += que.top(); que.pop();
    }
    cout << ans << endl;
    
    return 0;
}