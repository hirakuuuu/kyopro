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
    int x, y; cin >> x >> y;
    int n = x*y, m = x*y;
    vector<pair<int, int>> edge;
    int tail = x;
    rep(i, 0, x){
        edge.push_back({i, (i+1)%x});
        edge.push_back({i, tail});
        rep(j, 0, y-2){
            edge.push_back({tail, tail+1});
            tail++;
        }
        tail++;
    }
    assert(edge.size() == m);
    cout << n << ' ' << m << endl;
    for(auto [a, b]: edge){
        cout << a+1 << ' ' << b+1 << endl;
    }
    return 0;
}