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
    int n, x; cin >> n >> x;
    vector<int> s(n), c(n);
    vector<long double> p(n);
    rep(i, 0, n){
        cin >> s[i] >> c[i];
        cin >> p[i];
        p[i] /= 100.0;
    }
    vector<vector<long double>> e(1<<n, vector<long double>(x+1));
    rrep(i, (1<<n)-1, 0){
        rep(j, 0, x+1){
            rep(k, 0, n){
                if((i>>k)&1 || j < c[k]) continue;
                int ni = i+(1<<k);
                chmax(e[i][j], p[k]*(e[ni][j-c[k]]+s[k])+(1.0-p[k])*(e[i][j-c[k]]));
            }
        }
    }
    cout << setprecision(20) <<  e[0][x] << endl;
    
    return 0;
}