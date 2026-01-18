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
    int n, k; cin >> n >> k;
    vector<int> p(n);
    vector<int> pos(n);
    rep(i, 0, n){
        cin >> p[i]; p[i]--;
        pos[p[i]] = i;
    }

    set<int> s;
    rep(i, 0, k){
        s.insert(pos[i]);
    }
    int ans = *s.rbegin()-*s.begin();
    rep(i, k, n){
        s.erase(pos[i-k]);
        s.insert(pos[i]);
        chmin(ans, *s.rbegin()-*s.begin());
    }
    cout << ans << endl;
    return 0;
}