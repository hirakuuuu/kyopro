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

    int n; cin >> n;
    vector<tuple<int, int, int>> event;
    vector<int> h(n), l(n);
    multiset<int> ms;
    rep(i, 0, n){
        cin >> h[i] >> l[i];
        event.emplace_back(l[i], h[i], -1);
        ms.insert(h[i]);
    }
    int q; cin >> q;
    vector<int> t(q);
    rep(i, 0, q){
        cin >> t[i];
        event.emplace_back(t[i], IINF, i);
    }

    sort(event.begin(), event.end());

    vector<int> ans(q);
    rep(i, 0, n+q){
        auto [time, height, id] = event[i];
        if(id != -1){
            assert(!ms.empty());
            ans[id] = *ms.rbegin();
        }else{
            ms.erase(ms.find(height));
        }
    }
    rep(i, 0, q){
        cout << ans[i] << '\n';
    }
    return 0;
}