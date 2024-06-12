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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, l, r; cin >> n >> l >> r;
    vector<vector<int>> g((1<<n)+1);
    rep(i, 0, n+1){
        for(int j = 0; j < (1<<n); j += (1<<i)){
            g[j].push_back(j+(1<<i));
            g[j+(1<<i)].push_back(j);
        }
    }
    vector<int> parent((1<<n)+1, -2);
    parent[r+1] = -1;
    queue<int> que;
    que.push(r+1);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(parent[nq] != -2) continue;
            parent[nq] = q;
            que.push(nq);
        }
    }

    int ans = 0;
    int now = l;
    while(parent[now] != -1){
        int p = parent[now];
        int pm = 1;
        int L = now, R = p;
        if(L > R){
            pm = -1;
            swap(L, R);
        }
        int i = -1, tmp = R-L;
        while(tmp){
            i++;
            tmp /= 2;
        }
        int j = (L>>i);
        cout << "? " << i << ' ' << j << endl;
        int t; cin >> t;
        ans += pm*t;
        ans %= 100;
        if(ans < 0) ans += 100;
        now = parent[now];
        // cout << now << ' ' << parent[now] << endl;
    }
    cout << "! " << ans << endl;


    
    return 0;
}