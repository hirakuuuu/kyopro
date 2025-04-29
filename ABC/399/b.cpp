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
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    rep(i, 0, n) cin >> p[i].first, p[i].second = i;
    sort(p.rbegin(), p.rend());

    int tmp = 1, cnt = 1;
    vector<int> ans(n);
    ans[p[0].second] = 1;
    rep(i, 1, n){
        if(p[i-1].first != p[i].first) tmp += cnt, cnt = 0;
        ans[p[i].second] = tmp;
        cnt++;
    }
    rep(i, 0, n){
        cout << ans[i] << endl;
    }
    return 0;
}