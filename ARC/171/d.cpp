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

/*
０になってはいけない区間を累積和でとらえると，同じ値になってはいけないということになる．
つまり，そこに辺を張ったグラフを考えると彩色に帰着できる．
グラフの彩色数は部分集合を列挙する愚直なDPで O(3^n) で計算可能
*/

int main(){
    int p, b, n, m; cin >> p >> b >> n >> m;
    vector<int> l(m), r(m);
    rep(i, 0, m){
        cin >> l[i] >> r[i];
        l[i]--;
    }

    if(n < p){
        // A_i = B^{-(n-i)} (mod.p) と取ればよい
        cout << "Yes" << endl;
        return 0;
    }

    vector<int> is_independent(1<<(n+1));
    rep(i, 0, 1<<(n+1)){
        bool ok = true;
        rep(j, 0, m){
            if((i>>l[j])&1 && (i>>r[j])&1){
                ok = false;
            }
        }
        is_independent[i] = ok;
    }

    vector<int> dp(1<<(n+1), IINF);
    dp[0] = 0;
    rep(i, 1, 1<<(n+1)){
        if(is_independent[i]) dp[i] = 1;
        for(int j = i; j != 0; j = (j-1)&i){
            if(is_independent[j]){
                chmin(dp[i], dp[i^j]+1);
            }
        }
    }


    if(dp[(1<<(n+1))-1] <= p) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}