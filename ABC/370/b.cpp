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
    vector<vector<int>> a(n, vector<int>(n, -1));
    rep(i, 0, n){
        rep(j, 0, i+1){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int tmp = 0;
    rep(g, 0, n){
        int i = tmp, j = g;
        if(i < j) swap(i, j);
        tmp = a[i][j];
    }
    cout << tmp+1 << endl;

    
    return 0;
}