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
現時点で自分が勝てない盤面であれば、それを変えずに相手に押し付けることで、先手必勝にできる典型

a_{i+1} - a_{i} >= 2 の場合
- a_{i+1} を a_{i} 未満にする遷移において、先手必勝の遷移先がないと仮定すると, 
- a_{i}+1 に遷移することで, 後手が先手必勝の盤面にしか遷移できなくなる
- よって、先手必勝

a_{i+1} - a_{i} = 1 の場合
- 先ほどの議論より, a_{i+1} - a_{i} >= 2 にはできないので、a_{i+1} - a_{i} = 1 を保って遷移することになる
- よって最大の操作階数を経由するので、その偶奇で判定
*/

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    if(a[n-1]-a[n-2] >= 2){
        cout << "Alice" << endl;
    }else{
        if((a[n-1]-n+1)%2 == 0) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
    
    return 0;
}