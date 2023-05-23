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

map<ll, ll> memo;

ll f(ll n){
    if(n%10 == 0) return 0;
    ll tmp = 1;
    while(tmp*10 < n) tmp *= 10;
    return (n%10)*tmp+n/10;
}

int main(){
    ll a, n; cin >> a >> n;

    vector<ll> dist(1000005, INF);
    dist[1] = 0;
    queue<ll> que;
    que.push(1);
    while(!que.empty()){
        ll q = que.front(); que.pop();
        ll p = q*a, r = f(q);
        if(p < 1000005 and dist[p] > dist[q]+1){
            dist[p] = dist[q]+1;
            que.push(p);
        }
        if(r < 1000005 and r > 0 and dist[r] > dist[q]+1){
            dist[r] = dist[q]+1;
            que.push(r);
        }
    }

    if(dist[n] == INF) cout << -1 << endl;
    else cout << dist[n] << endl;
    

    
    return 0;
}