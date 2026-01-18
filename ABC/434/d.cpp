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
    vector<vector<int>> acc(2005, vector<int>(2005));
    vector<int> u(n), d(n), l(n), r(n);
    rep(i, 0, n){
        cin >> u[i] >> d[i] >> l[i] >> r[i];
        acc[u[i]][l[i]]++;
        acc[u[i]][r[i]+1]--;
        acc[d[i]+1][l[i]]--;
        acc[d[i]+1][r[i]+1]++;
    }

    rep(i, 0, 2005){
        rep(j, 1, 2005){
            acc[i][j] += acc[i][j-1];
        }
    }
    rep(j, 0, 2005){
        rep(i, 1, 2005){
            acc[i][j] += acc[i-1][j];
        }
    }


    int ans = 0;
    rep(i, 1, 2001){
        rep(j, 1, 2001){
            if(acc[i][j] == 0) ans++;
        }
    }

    vector<vector<int>> acc2(2005, vector<int>(2005));
    rep(i, 1, 2001){
        rep(j, 1, 2001){
            if(acc[i][j] == 1) acc2[i][j]++;
        }
    }
    rep(i, 1, 2001){
        rep(j, 1, 2001){
            acc2[i][j] += acc2[i][j-1]+acc2[i-1][j]-acc2[i-1][j-1];
        }
    }

    rep(i, 0, n){
        cout << ans+(acc2[d[i]][r[i]]-acc2[u[i]-1][r[i]]-acc2[d[i]][l[i]-1]+acc2[u[i]-1][l[i]-1]) << endl;
    }

    return 0;
}