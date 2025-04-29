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
    vector<vector<int>> c(n, vector<int>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> c[i][j];
        }
    }

    vector<int> d(n-1);
    rep(i, 0, n-1) d[i] = c[0][i+1]-c[0][i];
    rep(i, 1, n){
        vector<int> e(n-1);
        rep(j, 0, n-1) e[j] = c[i][j+1]-c[i][j];
        if(d != e){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    vector<int> a(n), b(n);
    int min_id = -1, mi = IINF;
    rep(i, 0, n){
        if(c[i][0] < mi){
            min_id = i;
            mi = c[i][0];
        }
    }

    b = c[min_id];
    rep(i, 0, n) a[i] = c[i][0]-b[0];
    rep(i, 0, n) cout << a[i] << ' ';
    cout << endl;
    rep(i, 0, n) cout << b[i] << ' ';
    cout << endl;
    
    return 0;
}