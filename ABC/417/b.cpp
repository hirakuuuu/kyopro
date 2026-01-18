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
    multiset<int> ms;
    rep(i, 0, n){
        int a; cin >> a;
        ms.insert(a);
    }
    rep(i, 0, m){
        int b; cin >> b;
        if(ms.count(b)){
            ms.erase(ms.find(b));
        }
    }

    for(auto mm: ms){
        cout << mm << ' ';
    }
    cout << endl;
    
    return 0;
}