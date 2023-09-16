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
// https://atcoder.jp/contests/abc320/tasks/abc320_b

int main(){
    string s; cin >> s;
    int n = s.size();
    int ans = 0;
    rep(i, 0, n){
        rep(j, 1, n-i+1){
            string t = s.substr(i, j);
            string u = t;
            reverse(u.begin(), u.end());
            if(t == u) chmax(ans, j);
        }
    }

    cout << ans << endl;
    
    return 0;
}