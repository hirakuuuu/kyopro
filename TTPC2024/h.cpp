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
    string s; cin >> s;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i], a[i]--;
    vector<int> x(4);
    rep(i, 0, 4) cin >> x[i], x[i]--;

    map<vector<int>, bool> seen;
    map<string, int> mx;
    int cnt = 0;
    while(seen.find(x) == seen.end()){
        seen[x] = true;
        string sx;
        rep(j, 0, 4) sx.push_back(s[x[j]]);
        // cout << sx << ' ' << cnt << endl;
        mx[sx] = cnt++;

        rep(j, 0, 4) x[j] = a[x[j]];
    }

    int ans = mx["TTPC"];
    bool err = false;
    // サイクルに TTPC があるかを判定
    map<vector<int>, bool> seen_;
    while(seen_.find(x) == seen_.end()){
        seen_[x] = true;
        string sx;
        rep(j, 0, 4) sx.push_back(s[x[j]]);
        if(sx == "TTPC") err = true;

        rep(j, 0, 4) x[j] = a[x[j]];
    }

    if(err) cout << "NeverEnds" << endl;
    else cout << ans << endl;

    


    return 0;
}