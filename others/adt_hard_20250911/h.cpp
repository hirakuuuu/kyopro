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
    map<pair<int, int>, bool> ff;
    while(q--){
        int t; cin >> t;
        int a, b; cin >> a >> b;
        if(t == 1){
            ff[{a, b}] = true;
        }else if(t == 2){
            ff[{a, b}] = false;
        }else{
            if(ff[{a, b}] && ff[{b, a}]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}