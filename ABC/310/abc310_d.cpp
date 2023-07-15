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
// https://atcoder.jp/contests/abc310/tasks/abc310_d


int main(){
    int n, t, m; cin >> n >> t >> m;
    vector<int> a(m), b(m);
    vector<vector<int>> g(n);
    rep(i, 0, m){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    vector<ll> ans(n), seen(n);
    vector<vector<int>> team
    rep(i, 0, n){
        if(seen[i]) continue;
        queue<int> que;
        que.push(i);
        seen[i] = true;

        vector<int> cnt(n);
        while(!que.empty()){
            int q = que.front(); que.pop();
            ans[q] = t-cnt[q];
            for(auto nq: g[q]){
                cnt[nq]++;
                if(seen[nq]) continue;
                que.push(nq);
                seen[nq] = true;
            }
        }
    }
    ll total = 1, offset = 1;
    rep(i, 0, n){
        cout << ans[i] << endl;
        total *= ans[i];
    }
    rep(i, 1, t+1) offset *= i;
    cout << total/offset << endl;
    return 0;
}