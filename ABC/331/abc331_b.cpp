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
// https://atcoder.jp/contests/abc331/tasks/abc331_b

int s, m, l;

int f(int n){
    if(n <= 0) return 0;
    return min({f(n-6)+s, f(n-8)+m, f(n-12)+l});
}

int main(){
    int n; cin >> n;
    cin >> s >> m >> l;
    cout << f(n) << endl;


    return 0;
}