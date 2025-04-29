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
    rep(i, 0, n){
        cin >> a[i];
    }

    set<int> ls, rs;
    vector<int> rcnt(n+1);
    rep(i, 0, n){
        rs.insert(a[i]);
        rcnt[a[i]]++;
    }

    int ans = -IINF;
    rep(i, 0, n){
        rcnt[a[i]]--;
        if(rcnt[a[i]] == 0) rs.erase(a[i]);
        ls.insert(a[i]);

        chmax(ans, (int)ls.size()+(int)rs.size());
    }
    cout << ans << endl;
    return 0;
}