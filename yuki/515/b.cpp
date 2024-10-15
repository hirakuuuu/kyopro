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
    string s, t; cin >> s >> t;
    vector<int> ans(4);
    rep(i, 0, 2) rep(j, 0, 2){
        if((s[i] == 'A' || t[j] == 'A') && (s[i] != 'B' && t[j] != 'B')) ans[0] += 25;
        else if((s[i] == 'B' || t[j] == 'B') && (s[i] != 'A' && t[j] != 'A')) ans[1] += 25;
        else if((s[i] == 'A' && t[j] == 'B') || (s[i] == 'B' && t[j] == 'A')) ans[2] += 25;
        else ans[3] += 25;
    }
    rep(i, 0, 4){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}