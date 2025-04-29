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
    int n, m; cin >> n >> m;
    vector<int> s(m);
    set<pair<int, int>> t;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    rep(i, 0, m){
        cin >> s[i];
        s[i]--;
        t.insert({min(p[s[i]], p[s[i]+1]), max({p[s[i]], p[s[i]+1]})});
        swap(p[s[i]], p[s[i]+1]);
    }
    cout << t.size() << endl;

    return 0;
}