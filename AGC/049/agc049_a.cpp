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
// https://atcoder.jp/contests/agc049/tasks/agc049_a

template<size_t sz> struct bitset_comparer {
    bool operator() (const bitset<sz> &b1, const bitset<sz> &b2) const {
        return b1.to_ulong() < b2.to_ulong();
    }
};

int main(){
    int n; cin >> n;
    vector<string> s(n);
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, 0, n){
        cin >> s[i];
        rep(j, 0, n){
            a[i][j] = (i == j || s[i][j]-'0');
        }
    }

    auto matmal = [&](vector<vector<int>> A, vector<vector<int>> B){
        vector<vector<int>> C(A.size(), vector<int>(B[0].size()));
        rep(i, 0, A.size()){
            rep(j, 0, B.size()){
                rep(l, 0, B[0].size()){
                    C[i][l] |= A[i][j]&B[j][l];
                }
            }
        }
        return C;
    };

    auto matpow = [&](vector<vector<int>> A, ll N){
        vector<vector<int>> C(A.size(), vector<int>(A[0].size()));
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

    vector<vector<int>> b = matpow(a, n);
    rep(i, 0, n){
        rep(j, 0, n){
            cout << b[i][j];   
        }
        cout << endl;
    }

    double ans = 0;
    rep(j, 0, n){
        double cnt = 0;
        rep(i, 0, n){
            cnt += b[i][j];
        }
        ans += 1.0/cnt;
    }
    printf("%.10f\n", ans);
 

    return 0;
}