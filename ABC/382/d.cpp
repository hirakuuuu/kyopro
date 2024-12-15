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
    vector<int> a(n);
    vector<vector<int>> ans;
    auto f = [&](auto self, int pos) -> void {
        if(pos == n){
            ans.push_back(a);
            return;
        }
        
        int r = m-(n-1-pos)*10+1;
        rep(i, a[pos-1]+10, r){
            a[pos] = i;
            self(self, pos+1);
        }
    };
    rep(i, 1, m-(n-1)*10+1){
        a[0] = i;
        f(f, 1);
    }

    cout << ans.size() << endl;
    for(auto A: ans){
        for(auto aa: A){
            cout << aa << ' ';
        }
        cout << endl;
    }
    return 0;
}