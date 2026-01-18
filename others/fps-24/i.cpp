#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];


    auto f = [&](auto self, int l, int r) -> vector<mint> {
        if(l >= r){
            return {1};
        }
        if(r-l == 1){
            return {1, a[l]};
        }

        vector<mint> b1 = self(self, l, (l+r)/2);
        vector<mint> b2 = self(self, (l+r)/2, r);
        vector<mint> c = convolution(b1, b2);
        while(c.size() > k+1) c.pop_back();
        return c; 
    };
    vector<mint> res = f(f, 0, n);
    cout << res[k].val() << endl;

    
    return 0;
}