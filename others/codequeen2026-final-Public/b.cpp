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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t, k; cin >> n >> m >> t >> k;
    vector<int> l(n), r(m);
    vector<int> lr(n+m);
    rep(i, 0, n) cin >> l[i], lr[i] = l[i];
    rep(i, 0, m) cin >> r[i], lr[i+n] = r[i];
    sort(lr.begin(), lr.end());

    vector<pair<int, int>> event;
    rep(i, 0, n+m){
        if(i < n+m-1 && lr[i] == lr[i+1]){
            event.emplace_back(lr[i], 2);
            i++;
        }else{
            event.emplace_back(lr[i], 1);
        }
    }

    int ans = 0;
    int pre = -1, len = 0;
    for(auto [val, cnt]: event){
        if(val-pre == 1 && cnt == 2) len++;
        else len = 1;
        ans += cnt;
        if(len == k+1) ans--, len = 0;
        pre = val;
    }
    cout << ans << endl;
    
    return 0;
}