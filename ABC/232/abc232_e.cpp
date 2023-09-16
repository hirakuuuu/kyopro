#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc232/tasks/abc232_e

int main(){
    ll h, w, k; cin >> h >> w >> k;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    vector<vector<ll>> A = {{
        (x1 == x2)&(y1 == y2),
        (x1 == x2)&(y1 != y2),
        (x1 != x2)&(y1 == y2),
        (x1 != x2)&(y1 != y2),
    }};

    vector<vector<ll>> B = {
        {0, (w-1)%MOD, (h-1)%MOD, 0},
        {1, (w-2)%MOD, 0, (h-1)%MOD},
        {1, 0, (h-2)%MOD, (w-1)%MOD},
        {0, 1, 1, ((h-2)+(w-2))%MOD},
    };

    auto matmal = [&](vector<vector<ll>> A, vector<vector<ll>> B){
        vector<vector<ll>> C(A.size(), vector<ll>(B[0].size()));
        rep(i, 0, A.size()){
            rep(j, 0, B.size()){
                rep(l, 0, B[0].size()){
                    C[i][l] += A[i][j]*B[j][l];
                    C[i][l] %= MOD;
                }
            }
        }
        return C;
    };

    auto matpow = [&](vector<vector<ll>> A, ll N){
        vector<vector<ll>> C(A.size(), vector<ll>(A[0].size()));
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

    vector<vector<ll>> M = matpow(B, k);
    vector<vector<ll>> ans = matmal(A, M);
    cout << ans[0][0] << endl;
    
    
    return 0;
}