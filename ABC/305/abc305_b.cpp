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
// https://atcoder.jp/contests/abc305/tasks/abc305_b

int main(){
    char p, q; cin >> p >> q;
    vector<int> dist = {0, 3, 4, 8, 9, 14, 23};
    if(p-'A' > q-'A') swap(p, q);
    cout << dist[q-'A']-dist[p-'A'] << endl;
    return 0;
}