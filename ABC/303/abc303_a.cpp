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
// https://atcoder.jp/contests/abc303/tasks/abc303_a

int main(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    rep(i, 0, n){
        if(s[i] == t[i]) continue;
        if((s[i] == 'l' && t[i] == '1') || (s[i] == '1' && t[i] == 'l')) continue;
        if((s[i] == 'o' && t[i] == '0') || (s[i] == '0' && t[i] == 'o')) continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    
    return 0;
}