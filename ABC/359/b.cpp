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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> a(2*n);
    vector<vector<int>> b(n);
    rep(i, 0, 2*n){
        cin >> a[i];
        a[i]--;
        b[a[i]].push_back(i);
    }
    int ans = 0;
    rep(i, 0, n){
        if(b[i][1]-b[i][0] == 2) ans++;
    }
    cout << ans << endl;
    
    return 0;
}