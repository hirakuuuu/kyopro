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
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }

    int ans = 0;
    rep(i, 0, n){
        vector<int> seen(n);
        seen[i] = true;
        queue<int> que;
        que.push(i);
        int cnt = 1;
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: g[q]){
                if(seen[nq]) continue;
                seen[nq] = true;
                que.push(nq);
                cnt++;
            }
        }
        ans += cnt;
    }
    cout << ans << endl;


    
    return 0;
}