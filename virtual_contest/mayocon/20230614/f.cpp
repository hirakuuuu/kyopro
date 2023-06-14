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
    vector<int> a(n), b(n);
    vector<vector<int>> g(m+1);
    vector<int> r(m+1);
    int max_a = 0, min_b = m+1;
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        g[a[i]].push_back(i);
        chmax(max_a, a[i]);
        chmin(min_b, b[i]);
    }
    r[1] = max_a;
    rep(i, 2, min_b+1){
        r[i]= r[i-1];
        for(auto ga: g[i-1]){
            chmax(r[i], b[ga]);
        }
    }

    vector<int> ans(m+1);
    rep(i, 1, min_b+1){
        ans[r[i]-i+1]++;
        ans[m-i+2]--;
    }
    rep(i, 1, m+1) ans[i] += ans[i-1];
    rep(i, 1, m+1) cout << ans[i] << ' ';
    cout << endl;
    
    return 0;
}