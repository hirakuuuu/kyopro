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
    vector<int> a = {0};
    int tmp = 0;
    rep(i, 0, n){
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    a.push_back(360);
    vector<int> c;
    rep(i, 1, a.size()){
        c.push_back(a[i]-a[i-1]);
    }
    sort(c.rbegin(), c.rend());
    vector<int> b(m);
    rep(i, 0, c.size()){
        b[i%m] += c[i];
    }
    rep(i, 0, m){
        cout << b[i] << endl;
    }
    return 0;
}