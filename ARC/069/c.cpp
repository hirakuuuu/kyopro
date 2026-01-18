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
    vector<int> a(n);
    map<int, vector<int>> ids;
    set<int> sa;
    rep(i, 0, n){
        cin >> a[i];
        ids[a[i]].push_back(i);
        sa.insert(a[i]);
    }

    vector<int> b(sa.begin(), sa.end());
    vector<ll> ans(n);
    int mi = n;
    for(auto i: ids[b.back()]) chmin(mi, i);
    int pre = b.back();
    int cnt = ids[b.back()].size();
    rrep(i, (int)b.size()-2, 0){
        if(mi == 0) break;
        // cout << mi << ' ' << b[i] << endl;
        ans[mi] += (ll)(pre-b[i])*cnt;
        for(auto id: ids[b[i]]){
            chmin(mi, id);
        }
        cnt += ids[b[i]].size();
        pre = b[i];
    }
    rep(i, 0, n){
        ans[0] += min(pre, a[i]);
    }
    rep(i, 0, n){
        cout << ans[i] << endl;
    }

    return 0;
}