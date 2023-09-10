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
// https://atcoder.jp/contests/abc221/tasks/abc221_f

vector<vector<int>> g(200005);

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

void get_dist(int s, vector<int> &dist, int obs = -1){
    fill(dist.begin(), dist.end(), -1);
    dist[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(nq == obs || dist[nq] != -1) continue;
            dist[nq] = dist[q]+1;
            que.push(nq);
        }
    }
}

int dfs(int pos, int par, int D, int d){
    if(d == D/2) return 1;
    int res = 0;
    for(auto npos: g[pos]){
        if(npos == par) continue;
        res += dfs(npos, pos, D, d+1);
    }
    return res;
}

int main(){
    int n; cin >> n;
    
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int D = 0, u = 0, v = 0;
    vector<int> dist(n);
    get_dist(0, dist);
    rep(i, 0, n){
        if(D < dist[i]){
            D = dist[i];
            u = i;
        }
    }

    get_dist(u, dist);
    rep(i, 0, n){
        if(D < dist[i]){
            D = dist[i];
            v = i;
        }
    }
    vector<int> dist_u = dist;
    get_dist(v, dist);
    if(D%2 == 0){
        int c = 0;
        rep(i, 0, n){
            if(dist[i] == D/2 && dist_u[i] == D/2){
                c = i;
                break;
            }
        }
        vector<int> cnt;
        ll ans = 1, sum = 0;
        for(auto nc: g[c]){
            ll tmp = dfs(nc, c, D, 1);
            ans *= tmp+1;
            ans %= MOD;
            sum += tmp;
        }
        cout << (ans-sum-1+MOD)%MOD << endl;
    }else{
        int a = 0, b = 0;
        rep(i, 0, n){
            if(dist_u[i] == D/2 && dist[i] == (D+1)/2) a = i;
            if(dist[i] == D/2 && dist_u[i] == (D+1)/2) b = i;
        }

        ll sum_a = 0, sum_b = 0;
        get_dist(a, dist, b);
        rep(i, 0, n){
            if(dist[i] == D/2) sum_a++;
        }
        get_dist(b, dist, a);
        rep(i, 0, n){
            if(dist[i] == D/2) sum_b++;
        }

        cout << (sum_a*sum_b)%MOD << endl;

    }


    
    return 0;
}