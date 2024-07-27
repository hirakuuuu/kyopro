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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
1次元の累積和を複数回取る様子は、二次元グリッド上で縦横に移動することと同じように考えられる
つまり, 操作回数 k を固定すると, a[i] が a[n] に寄与するかどうかは \binom{n-i+k-1}{k-1} が奇数かどうかで判定できる
二項係数が奇数かどうかはリュカの定理から, N-i と k-1 の立っている bit の位置がすべて異なることと同値らしい
これは ~(N-i) が k-1 を完全に含んでいることと同じなので, 高速ゼータ変換できる. 
*/

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    int h = 0, s = 1;
    while(s < max(n, m)){
        s <<= 1;
        h++;
    }

    // 高速ゼータ変換
    // 今回は含んでいない方で集めたい
    vector<int> b(s);
    rep(i, 0, n) b[s-(n-i)] = a[i]; // 最初は完全に含んでいないところから始める
    rep(i, 0, h){
        rep(x, 0, s){
            if((x>>i)&1){
                b[x-(1<<i)] ^= b[x]; // i番目のビットを０にしても含んでいない
            }
        }
    }
    rep(i, 0, m){
        cout << b[i] << ' ';
    }
    cout << endl;
    
    return 0;
}