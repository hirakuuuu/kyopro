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
    int n, k; cin >> n >> k;
    vector<int> a(1<<n, k/(1<<n));
    // map<pair<int, int>, bool> seen;
    auto f = [&](auto self, int l, int r, int rest) -> void {
        if(r-l == 1){
            a[l] += rest;
            return;
        }
        self(self, l, (l+r)/2, (rest+1)/2);
        self(self, (l+r)/2, r, (rest)/2);
    };
    f(f, 0, 1<<n, k%(1<<n));

    vector<int> b = a;
    int x = 0;
    rep(i, 0, n){
        int mx = -IINF, mi = IINF;
        rep(j, 0, 1<<(n-i)){
            chmax(mx, b[j]);
            chmin(mi, b[j]);
        }
        chmax(x, mx-mi);
        vector<int> b_;
        for(int j = 0; j < 1<<(n-i); j += 2){
            b_.push_back(b[j]+b[j+1]);
        }
        swap(b_, b);
    }
    cout << x << endl;
    rep(i, 0, 1<<n){
        cout << a[i] << ' ';
    }
    cout << endl;

    
    return 0;
}