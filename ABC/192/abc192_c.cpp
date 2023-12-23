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
// https://atcoder.jp/contests/abc192/tasks/abc192_c

int main(){
    ll n, k; cin >> n >> k;
    rep(i, 0, k){
        string s = to_string(n), t = to_string(n);
        sort(s.begin(), s.end());
        sort(t.rbegin(), t.rend());
        ll g1 = stol(t), g2 = stol(s);
        n = g1-g2;
        // cout << g1 << ' ' << g2 << ' ' << n << endl;
    }
    cout << n << endl;
    
    return 0;
}