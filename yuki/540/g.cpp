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
    int max = 8000;
    vector<pair<int, int>> ans;
    auto query = [&](auto self, int xl, int xr, int yl, int yr) -> void {


        assert(max > 0);
        max--;
        cout << "? " << xl << ' ' << xr << ' ' << yl << ' ' << yr << endl;
        int res; cin >> res;
        if(res == 0) return;

        if(xl == xr && yl == yr){
            ans.push_back({xl, yl});
            return;
        }

        if(xl != xr){
            // if((xl+xr))
            self(self, xl, (xl+xr)/2, yl, yr);
            self(self, (xl+xr)/2+1, xr, yl, yr);
        }else{
            self(self, xl, xr, yl, (yl+yr)/2);
            self(self, xl, xr, (yl+yr)/2+1, yr);
        }
    };

    query(query, 0, 1000000, 0, 1000000);
    // query(query, 0, 5, 0, 5);

    cout << "! " << ans.size() << endl;
    for(auto [x, y]: ans){
        cout << x << ' ' << y << endl;
    }
    
    return 0;
}