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
    string s, t; cin >> s >> t;
    vector<int> acc(n+1);
    rep(i, 0, m){
        int l, r; cin >> l >> r; l--;
        acc[l]++;
        acc[r]--;
    }
    rep(i, 0, n){
        acc[i+1] += acc[i];
        acc[i] %= 2;
    }
    rep(i, 0, n){
        if(acc[i]) cout << t[i];
        else cout << s[i];
    }
    cout << endl;
    return 0;
}