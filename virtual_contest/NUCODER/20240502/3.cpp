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
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    vector<vector<int>> r(h), c(w);
    rep(i, 0, h) r[i].push_back(-1);
    rep(i, 0, w) c[i].push_back(-1);
    rep(i, 0, h){
        rep(j, 0, w){
            if(s[i][j] == '#'){
                r[i].push_back(j);
                c[j].push_back(i);
            }
        }
    }
    rep(i, 0, h) r[i].push_back(w);
    rep(i, 0, w) c[i].push_back(h);
    int ans = 0;
    rep(i, 0, h){
        rep(j, 0, w){
            if(s[i][j] == '#') continue;
            int cnt = 0;
            int rr = upper_bound(r[i].begin(), r[i].end(), j)-r[i].begin();
            cnt += r[i][rr]-r[i][rr-1]-1;
            int cr = upper_bound(c[j].begin(), c[j].end(), i)-c[j].begin();
            cnt += c[j][cr]-c[j][cr-1]-1;
            chmax(ans, cnt-1);
        }
    }
    cout << ans << endl;
    return 0;
}