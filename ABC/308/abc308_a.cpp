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
// https://atcoder.jp/contests/abc308/tasks/abc308_a

int main(){
    vector<int> s(8);
    rep(i, 0, 8) cin >> s[i];

    bool f = true;
    rep(i, 0, 7) f &= (s[i] <= s[i+1]);
    rep(i, 0, 8) f &= (100 <= s[i] && s[i] <= 675);
    rep(i, 0, 8) f &= (s[i]%25 == 0);
    

    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}