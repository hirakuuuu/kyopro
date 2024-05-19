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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}



int main(){
    // int n; cin >> n;
    // vector<int> a(n), c(n);
    // rep(i, 0, n) cin >> a[i] >> c[i];

    // set<pair<int, int>> cost;
    // set<pair<int, int>> power;
    // rep(i, 0, n){
    //     cost.insert({-c[i], i});
    //     power.insert({-a[i], i});
    // }
    // vector<bool> del(n);
    // rep(i, 0, n){
    //     auto [pa, id] = *(power.begin());
    //     pa *= -1;
    //     power.erase(power.begin());
    //     if(del[id]) continue;
    //     while(!cost.empty() && (*cost.begin()).first < -c[id]){
    //         auto [c_, id_] = *cost.begin();
    //         del[id_] = true;
    //         cost.erase(cost.begin());
    //     }
    //     if(!cost.empty()) cost.erase(cost.begin());
    // }

    // set<int> ans;
    // rep(i, 0, n){
    //     if(!del[i]) ans.insert(i+1);
    // }
    // cout << ans.size() << endl;
    // for(auto aa: ans){
    //     cout << aa << ' ';
    // }
    // cout << endl;

    int n; cin >> n;
    vector<tuple<int, int, int>> ca(n);
    rep(i, 0, n){
        int a, c; cin >> a >> c;
        ca[i] = {c, a, i+1};
    }
    sort(ca.begin(), ca.end());
    int mx = 0;
    set<int> ans;
    rep(i, 0, n){
        auto [c, a, id] = ca[i];
        if(a < mx) continue;
        ans.insert(id);
        mx = a;
    }
    cout << ans.size() << endl;
    for(auto aa: ans){
        cout << aa << ' ';
    }
    cout << endl;


    
    return 0;
}