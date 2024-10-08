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
    string s; cin >> s;
    vector<int> p(26);
    rep(i, 0, 26){
        p[s[i]-'A'] = i;
    }
    int pos = p[0];
    int ans = 0;
    rep(i, 1, 26){
        ans += abs(p[i]-p[i-1]);
        pos = p[i];
    }
    cout << ans << endl;
    return 0;
}