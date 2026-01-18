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
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    // sort(a.begin(), a.end());

    mint pr1 = 1;
    rep(i, 0, n){
        if(a[i] <= k) continue;
        pr1 *= mint(k)/a[i];
    }
    mint pr2 = 1;
    rep(i, 0, n){
        if(a[i] <= k-1) continue;
        pr2 *= mint(k-1)/a[i];
    }
    cout << (pr1-pr2).val() << endl;
    return 0;
}