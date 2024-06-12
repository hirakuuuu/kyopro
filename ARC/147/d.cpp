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
操作列を固定すると、最初の集合が 2^m 通りで、それ以降の集合は一意に定まる
各集合に対して、x を含む場合の個数を A_x , 含まない場合の個数を B_x とする
このときのスコアは Π_{i=1}^{m}(A_x+B_x) = n^m となる.
後は 操作列が m^{n-1} であることから、答えは m^{n-1}*n^m.
*/

int main(){
    int n, m; cin >> n >> m;
    mint e = mint(n)/2;
    cout << (e.pow(m)*mint(2).pow(m)*mint(m).pow(n-1)).val() << endl;
    
    return 0;
}