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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll k; cin >> k;
    auto matmal = [&](vector<vector<mint>> A, vector<vector<mint>> B){
        vector<vector<mint>> C(A.size(), vector<mint>(B[0].size()));
        rep(i, 0, A.size()){
            rep(j, 0, B.size()){
                rep(l, 0, B[0].size()){
                    C[i][l] += A[i][j]*B[j][l];
                }
            }
        }
        return C;
    };
    auto matpow = [&](vector<vector<mint>> A, ll N){
        vector<vector<mint>> C(A.size(), vector<mint>(A[0].size()));
        rep(i, 0, A.size()){
            C[i][i] = 1;
        }

        ll tmp = N;
        while(tmp){
            if(tmp&1) C = matmal(C, A);
            A = matmal(A, A);
            tmp >>= 1;
        }

        return C;
    };

    vector<vector<mint>> A = {{1, 1}, {1, 0}};
    A = matpow(A, k-1);
    cout << A[0][0].val() << endl;
    return 0;
}