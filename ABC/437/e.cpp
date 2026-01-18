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
    int n; cin >> n;
    vector<int> x(n+1), y(n+1);
    vector<int> pos(n+1, -1);
    pos[0] = 0;
    map<int, map<int, int>> v;
    int tmp = 1;
    vector<vector<int>> g(n+1);
    rep(i, 1, n+1){
        cin >> x[i] >> y[i];
        if(!v[pos[x[i]]].count(y[i])){
            v[pos[x[i]]][y[i]] = tmp++;
        }
        pos[i] = v[pos[x[i]]][y[i]];
        g[pos[i]].push_back(i);
    }

    vector<int> p;
    auto f = [&](auto self, int pos, int pre) -> void {
        for(auto nxt: g[pos]){
            p.push_back(nxt);
        }
        for(auto [_, nxt]: v[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
        }
    };
    f(f, 0, -1);

    rep(i, 0, n){
        cout << p[i] << ' ';
    }
    cout << endl;

    // 0: {}
    // 1: {72}
    // 2: {82}
    // 3: {82}
    // 4: {82, 75}
    // 5: {72, 83}
    // 6: {82, 75, 64}
    // 7: {72, 21}
    // 8: {82, 75}
    // 1, 7, 5, 2, 3, 4, 8, 6
    
    return 0;
}