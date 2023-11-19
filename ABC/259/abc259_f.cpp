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
    vector<int> d(n), cnt(n);
    rep(i, 0, n) cin >> d[i];
    vector<tuple<int, int, ll>> edge(n-1);
    ll sum = 0;
    rep(i, 0, n-1){
        int u, v;
        ll w; cin >> u >> v >> w;
        u--, v--;
        edge[i] = {w, u, v};
        cnt[u]++;
        cnt[v]++;
        sum += w;
    }
    sort(edge.begin(), edge.end());

    rep(i, 0, n-1){
        auto [w, u, v] = edge[i];
        if(w <= 0){
            cnt[u]--;
            cnt[v]--;
            sum -= w;
        }else{
            if(cnt[u] > d[u] || cnt[v] > d[v]){
                cnt[u]--;
                cnt[v]--;
                sum -= w;
            }
        }
    }

    cout << sum << endl;
    return 0;
}