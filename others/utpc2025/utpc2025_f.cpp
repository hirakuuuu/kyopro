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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> acc(n+1);
    rep(i, 1, n+1){
        if(s[i-1] == '(') acc[i] = acc[i-1]+1;
        else acc[i] = acc[i-1]-1;
    }
https://atcoder.jp/contests/ahc061/standings
    while(q--){
        int l, r; cin >> l >> r;
        if(acc[r]-acc[l-1] == 0) cout << "Infinite" << endl;
        else cout << "Finite" << endl;
    }
    return 0;
}