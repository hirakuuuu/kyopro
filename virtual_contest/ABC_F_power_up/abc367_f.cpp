#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint2 = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
- ハッシュ値を構成する
- 乱数振ってでかいmodにすればOK
*/


int main(){
    mt19937_64 rnd(0);
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n);
    vector<mint> a1(n);
    map<int, ll> memo;
    rep(i, 0, n){
        cin >> a[i];
        if(!memo.count(a[i])) memo[a[i]] = rnd();
        a1[i] = memo[a[i]];
    }
    vector<mint> b1(n);
    rep(i, 0, n){
        cin >> b[i];
        if(!memo.count(b[i])) memo[b[i]] = rnd();
        b1[i] = memo[b[i]];
    }

    vector<mint> acc_a(n+1), acc_b(n+1);
    rep(i, 1, n+1){
        acc_a[i] = acc_a[i-1]+a1[i-1];
        acc_b[i] = acc_b[i-1]+b1[i-1];
    }

    rep(i, 0, q){
        int l, r, L, R; cin >> l >> r >> L >> R;
        if(acc_a[r]-acc_a[l-1] == acc_b[R]-acc_b[L-1]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    
    return 0;
}