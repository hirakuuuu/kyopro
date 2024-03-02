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
    ll n, a, b, c; cin >> n >> a >> b >> c;
    vector<vector<ll>> d(n, vector<ll>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> d[i][j];
        }
    }

    vector<vector<ll>> ans(n, vector<ll>(2, INF));
    ans[0][0] = ans[0][1] = 0;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
    que.push({0, 0, 0});
    que.push({0, 0, 1});
    while(!que.empty()){
        auto [dist, u, e] = que.top(); que.pop();
        if(ans[u][e] < dist) continue;
        rep(i, 0, n){
            if(e == 0){
                if(dist+d[u][i]*a < ans[i][0]){
                    ans[i][0] = dist+d[u][i]*a;
                    que.push({ans[i][0], i, 0});
                }
            }
            if(dist+d[u][i]*b+c < ans[i][1]){
                ans[i][1] = dist+d[u][i]*b+c;
                que.push({ans[i][1], i, 1});
            }
        }
    }

    cout << min(ans[n-1][0], ans[n-1][1]) << endl;    
    return 0;
}