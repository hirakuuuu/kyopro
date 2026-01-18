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

    auto matmal = [&](vector<vector<uint32_t>> A, vector<vector<uint32_t>> B){
        vector<vector<uint32_t>> C(A.size(), vector<uint32_t>(B[0].size()));
        rep(i, 0, A.size()){
            rep(j, 0, B.size()){
                rep(l, 0, B[0].size()){
                    C[i][l] ^= (A[i][j]&B[j][l]);
                }
            }
        }
        return C;
    };

    auto matpow = [&](vector<vector<uint32_t>> A, ll N){
        vector<vector<uint32_t>> C(A.size(), vector<uint32_t>(A[0].size()));
        rep(i, 0, A.size()){
            C[i][i] = (1UL<<32)-1;
        }

        ll tmp = N;
        while(tmp){
            if(tmp&1) C = matmal(C, A);
            A = matmal(A, A);
            tmp >>= 1;
        }

        return C;
    };


    int k, m; cin >> k >> m;
    vector<uint32_t> a(k), c(k);
    rep(i, 0, k) cin >> a[i];
    rep(i, 0, k) cin >> c[i];

    vector<vector<uint32_t>> A(k, vector<uint32_t>(k));
    uint32_t ans = 0;
    rep(i, 0, k) A[0][i] = c[i];
    rep(i, 1, k) A[i][i-1] = (1UL<<32)-1;

    vector<uint32_t> x(k);
    rep(i, 0, k) x[k-1-i] = a[i];

    vector<vector<uint32_t>> B = matpow(A, m-1);
    rep(j, 0, k) ans ^= (B[k-1][j]&x[j]);
    cout << ans << endl;
    return 0;
}