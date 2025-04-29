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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    auto calc = [&](int x, int l) -> bool {
        int pl = lower_bound(a.begin(), a.end(), x-l)-a.begin();
        int pr = upper_bound(a.begin(), a.end(), x+l)-a.begin();
        int len = pr-pl;
        // [pl, pr) と [N-len, N) に共通部分があるかどうか
        return pr <= n-len;
    };

    while(q--){
        int x; cin >> x;
        int ok = 0, ng = IINF;
        while(ng-ok > 1){
            int mid = (ok+ng)/2;
            if(calc(x, mid)) ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
    }
    
    return 0;
}