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
    vector<int> a(2*n);
    vector<pair<int, int>> p0;
    vector<pair<int, int>> p1;
    rep(i, 0, n){
        cin >> a[i];
        if(i%2 == 0) p0.push_back({a[i], i});
        else p1.push_back({a[i], i});
    }
    sort(p0.begin(), p0.end());
    sort(p1.rbegin(), p1.rend());

    string ans(2*n);
    rep(i, 0, n){
        // i
    }
    
    
    
    return 0;
}