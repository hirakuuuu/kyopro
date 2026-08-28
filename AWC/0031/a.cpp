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
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> v(n);
    vector<vector<int>> t(n);
    rep(i, 0, n){
        cin >> v[i].first;
        v[i].second = -i;
        int c; cin >> c;
        rep(j, 0, c){
            int d; cin >> d;
            t[i].push_back(d);  
        }
    }
    sort(v.begin(), v.end());
    vector<int> cnt(m);
    rrep(i, n-1, n-k){
        rep(j, 0, t[-v[i].second].size()){
            cnt[t[-v[i].second][j]-1]++;
        }
    }

    int ans = 0;
    rep(i, 0, m){
        if(cnt[i] == k) ans++;
    }
    cout << ans << endl;
    return 0;
}