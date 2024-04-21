#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> a(n), rev(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
        rev[a[i]] = i;
    }
    vector<pair<int, int>> ans;
    rep(i, 0, n){
        if(rev[i] == i) continue;
        int p = rev[i], q = rev[a[i]];
        if(p > q) swap(p, q);
        ans.push_back({p+1, q+1});
        swap(rev[i], rev[a[i]]);
        swap(a[p], a[q]);
    }
    cout << ans.size() << endl;
    for(auto [i, j]: ans){
        cout << i << ' ' << j << endl;
    }
    
    return 0;
}