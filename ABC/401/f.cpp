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
    int D = 0;
    int n1; cin >> n1;
    vector<vector<int>> g1(n1);
    rep(i, 0, n1-1){
        int u, v; cin >> u >> v; u--, v--;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    vector<int> dl(n1, -1);
    vector<int> dr(n1, -1);
    {
        // 直径の端点を求める
        vector<int> dist(n1, -1);
        queue<int> que;
        que.push(0);
        dist[0] = 0;
        while(!que.empty()){
            int q_ = que.front(); que.pop();
            for(auto nq: g1[q_]){
                if(dist[nq] != -1) continue;
                dist[nq] = dist[q_]+1;
                que.push(nq);
            }
        }
        int L = 0;
        rep(i, 1, n1){
            if(dist[L] < dist[i]) L = i;
        }

        fill(dist.begin(), dist.end(), -1);
        que.push(L);
        dist[L] = 0;
        while(!que.empty()){
            int q_ = que.front(); que.pop();
            for(auto nq: g1[q_]){
                if(dist[nq] != -1) continue;
                dist[nq] = dist[q_]+1;
                que.push(nq);
            }
        }
        int R = 0;
        rep(i, 1, n1){
            if(dist[R] < dist[i]) R = i;
        }

        que.push(L);
        dl[L] = 0;
        while(!que.empty()){
            int q_ = que.front(); que.pop();
            for(auto nq: g1[q_]){
                if(dl[nq] != -1) continue;
                dl[nq] = dl[q_]+1;
                que.push(nq);
            }
        }
        que.push(R);
        dr[R] = 0;
        while(!que.empty()){
            int q_ = que.front(); que.pop();
            for(auto nq: g1[q_]){
                if(dr[nq] != -1) continue;
                dr[nq] = dr[q_]+1;
                que.push(nq);
            }
        }
        chmax(D, dl[R]);
    }


    int n2; cin >> n2;
    vector<vector<int>> g2(n2);
    rep(i, 0, n2-1){
        int u, v; cin >> u >> v; u--, v--;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }
    vector<int> dl2(n2, -1);
    vector<int> dr2(n2, -1);
    {
        // 直径の端点を求める
        vector<int> dist(n2, -1);
        queue<int> que;
        que.push(0);
        dist[0] = 0;
        while(!que.empty()){
            int q_ = que.front(); que.pop();
            for(auto nq: g2[q_]){
                if(dist[nq] != -1) continue;
                dist[nq] = dist[q_]+1;
                que.push(nq);
            }
        }
        int L = 0;
        rep(i, 1, n2){
            if(dist[L] < dist[i]) L = i;
        }

        fill(dist.begin(), dist.end(), -1);
        que.push(L);
        dist[L] = 0;
        while(!que.empty()){
            int q_ = que.front(); que.pop();
            for(auto nq: g2[q_]){
                if(dist[nq] != -1) continue;
                dist[nq] = dist[q_]+1;
                que.push(nq);
            }
        }
        int R = 0;
        rep(i, 1, n2){
            if(dist[R] < dist[i]) R = i;
        }

        que.push(L);
        dl2[L] = 0;
        while(!que.empty()){
            int q_ = que.front(); que.pop();
            for(auto nq: g2[q_]){
                if(dl2[nq] != -1) continue;
                dl2[nq] = dl2[q_]+1;
                que.push(nq);
            }
        }
        que.push(R);
        dr2[R] = 0;
        while(!que.empty()){
            int q_ = que.front(); que.pop();
            for(auto nq: g2[q_]){
                if(dr2[nq] != -1) continue;
                dr2[nq] = dr2[q_]+1;
                que.push(nq);
            }
        }
        chmax(D, dl2[R]);
    }

    vector<ll> mx(n1), mx2(n2);
    rep(i, 0, n1) mx[i] = max(dl[i], dr[i]);
    rep(i, 0, n2) mx2[i] = max(dl2[i], dr2[i]);
    sort(mx2.begin(), mx2.end());

    vector<ll> acc2(n2+1);
    rep(i, 0, n2) acc2[i+1] = acc2[i]+mx2[i];

    ll ans = (ll)n1*n2;
    rep(i, 0, n1) ans += mx[i]*n2;
    rep(i, 0, n2) ans += mx2[i]*n1;


    rep(i, 0, n1){
        ll num = lower_bound(mx2.begin(), mx2.end(), D-mx[i]-1)-mx2.begin();
        ans += num*D;
        ans -= num*(mx[i]+1);
        ans -= acc2[num];
    }


    cout << ans << endl;

    
    
    return 0;
}