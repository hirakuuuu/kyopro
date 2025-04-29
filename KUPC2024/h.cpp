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
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    random_device seed_gen;
    mt19937 engine(seed_gen());

    int N = 1000000;
    int Q = 900000;
    int cnt_wa = 0;

    rep(i, 2, 101){
        ll tmp = i;
        unordered_map<ll, bool> used;
        used[tmp] = true;
        rep(_, 0, 500000){
            tmp *= MOD;
            if(used)

        }
        bool WA = false;
        vector<ll> F(N+1);
        rep(i, 1, N+1){
            F[i] = engine()%(MOD-1)+1;
            cout << F[i] << endl;
            if(used[F[i]]){
                WA = true;
            }
            used[F[i]] = true;
        }
        if(WA) cnt_wa++;
    }
    cout << cnt_wa << endl;



    return 0;
}