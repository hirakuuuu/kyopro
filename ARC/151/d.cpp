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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
桁ごとに操作を行っても、大丈夫（こういう問題はこういうのが多い）
正当性は、2次元累積和を行方向からやるか列方向からやるかを変えてもＯＫなのと同じ感覚
後は行列を考えればＯＫ
*/

int main(){
    int n, q; cin >> n >> q;
    vector<mint> a(1<<n);
    rep(i, 0, 1<<n){
        int A; cin >> A;
        a[i] = A;
    }

    vector<vector<int>> queri(n);
    rep(i, 0, q){
        int x, y; cin >> x >> y;
        queri[x].push_back(y);
    }
    vector<vector<vector<mint>>> m = {
        {{1, 1}, {0, 1}},
        {{1, 0}, {1, 1}},
    };
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
    rep(i, 0, n){
        vector<vector<mint>> b(2, vector<mint>(2));
        b[0][0] = b[1][1] = 1;
        for(auto y: queri[i]) b = matmal(b, m[y]);
        rep(j, 0, 1<<n){
            if((j>>i)&1){
                vector<mint> c = {a[j-(1<<i)], a[j]};
                a[j-(1<<i)] = c[0]*b[0][0]+c[1]*b[1][0];
                a[j] = c[0]*b[0][1]+c[1]*b[1][1];
            }
        }
    }
    rep(i, 0, 1<<n){
        cout << a[i].val() << ' ';
    }
    cout << endl;
    
    return 0;
}