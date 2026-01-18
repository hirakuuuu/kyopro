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

template <typename T>
pair<T, vector<int>> hungarian(vector<vector<T>> &A) {
    const T infty = numeric_limits<T>::max();
    const int N = (int)A.size();
    const int M = (int)A[0].size();
    vector<int> P(M), way(M);
    vector<T> U(N, 0), V(M, 0), minV;
    vector<bool> used;

    for (int i = 1; i < N; i++) {
        P[0] = i;
        minV.assign(M, infty);
        used.assign(M, false);
        int j0 = 0;
        while (P[j0] != 0) {
            int i0 = P[j0], j1 = 0;
            used[j0] = true;
            T delta = infty;
            for (int j = 1; j < M; j++) {
                if (used[j]) continue;
                T curr = A[i0][j] - U[i0] - V[j];
                if (curr < minV[j]) minV[j] = curr, way[j] = j0;
                if (minV[j] < delta) delta = minV[j], j1 = j;
            }
            for (int j = 0; j < M; j++) {
                if (used[j])
                    U[P[j]] += delta, V[j] -= delta;
                else
                    minV[j] -= delta;
            }
            j0 = j1;
        }
        do {
            P[j0] = P[way[j0]];
            j0 = way[j0];
        } while (j0 != 0);
    }
    return {-V[0], P};
}

int main(){
    int n; cin >> n;
    vector<pair<int, int>> p(n), q(n);
    rep(i, 0, n) cin >> p[i].first >> p[i].second;
    rep(i, 0, n) cin >> q[i].first >> q[i].second;
    vector<vector<long double>> a(n+1, vector<long double>(n+1));
    rep(i, 0, n) rep(j, 0, n){
        a[j+1][i+1] = sqrt((p[i].first-q[j].first)*(p[i].first-q[j].first)+(p[i].second-q[j].second)*(p[i].second-q[j].second));
    }
    auto [_, r] = hungarian(a);
    rep(i, 1, n+1){
        cout << r[i] << ' ';
    }
    cout << endl;
    return 0;
}