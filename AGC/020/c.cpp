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
相補的な部分和をペアにすると、その２つの和は数列の総和に一致する. 
このとき, ペアの内小さい方の集合と大きい方の集合に分けると, 求める値は大きい方の集合の最小値. 
また, 大きい方の値は (sum+1)/2 以上. 
よって, 作れる数字の内, (sum+1)/2 以上で最小のものを答える.
bitset で高速化する必要がある. 
*/

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    int sum = 0;
    rep(i, 0, n) sum += a[i];

    bitset<4000001> b;
    b.set(0);
    rep(i, 0, n){
        b = b|(b<<a[i]);
    }
    rep(i, (sum+1)/2, 4000001){
        if(b[i]){
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}