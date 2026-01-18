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
    int l, r; cin >> l >> r;
    set<string> lang;
    rep(i, l, r+1){
        if(inr(1, i, 296)) lang.insert("c++");
        if(inr(296, i, 417)) lang.insert("rust");
        if(inr(417, i, 421)) lang.insert("python");
    }
    cout << (int)lang.size()-1 << endl;
    
    return 0;
}