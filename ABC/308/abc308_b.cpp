#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc308/tasks/abc308_b

int main(){
    int n, m; cin >> n >> m;
    vector<string> c(n);
    rep(i, 0, n) cin >> c[i];
    vector<string> d(m);
    rep(i, 0, m) cin >> d[i];
    vector<int> p(m+1);
    map<string, int> D;
    rep(i, 0, m+1){
        cin >> p[i];
        if(i > 0){
            D[d[i-1]] = p[i];
        }
    }

    int ans = 0;
    rep(i, 0, n){
        if(D[c[i]] == 0) ans+= p[0];
        else ans += D[c[i]];
    }
    cout << ans << endl;
    return 0;
}