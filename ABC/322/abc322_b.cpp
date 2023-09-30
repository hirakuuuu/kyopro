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
// https://atcoder.jp/contests/abc322/tasks/abc322_b

int main(){
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    bool f1 = (s == t.substr(0, n));
    bool f2 = (s == t.substr(m-n, n));

    if(f1 && f2) cout << 0 << endl;
    else if(!f1 && !f2) cout << 3 << endl;
    else cout << 2*f2+f1 << endl;

    return 0;
}