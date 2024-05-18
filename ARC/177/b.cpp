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

int main(){
    int n; cin >> n;
    string s; cin >> s;
    string ans;
    rrep(i, n-1, 0){
        if(s[i] == '0') continue;
        // s[0:i] = "000000" -> "1111111" -> "0000000"
        rep(j, 0, i+1) ans += 'A';
        rep(j, 0, i) ans += 'B';
    }
    cout << ans.size() << endl;
    cout << ans << endl;

    return 0;
}