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
// https://atcoder.jp/contests/abc131/tasks/abc131_f

int main(){
    int n; cin >> n;
    vector<vector<int>> g(400005);
    rep(i, 0, n){
        int x, y; cin >> x >> y;
        x--, y--;
        g[2*x].push_back(2*y+1);
        g[2*y+1].push_back(2*x);
    }

    vector<bool> seen(400005);
    queue<int> que;
    vector<ll> cnt(2);
    ll edge = 0, ans = 0;
    rep(i, 0, 400005){
        if(seen[i]) continue;
        seen[i] = true;
        que.push(i);
        cnt[0] = cnt[1] = 0;
        cnt[i%2]++;
        edge = g[i].size();
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: g[q]){
                if(seen[nq]) continue;
                seen[nq] = true;
                que.push(nq);
                cnt[nq%2]++;
                edge += g[nq].size();
            }
        }
        ans += (cnt[0]*cnt[1])-edge/2;
    }

    cout << ans << endl;

    
    return 0;
}