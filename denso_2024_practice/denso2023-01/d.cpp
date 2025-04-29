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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){

    auto f = [&](string s) -> int{
        int res = 0;
        rep(i, 0, 10){
            res += (s[i]-'0')*(i+1);
        }
        return res;
    };

    string s; cin >> s;
    int n = (int)s.size();
    int p = -1;
    rep(i, 0, n){
        if(s[i] == '?') p = i;
    }

    string ans;
    int cnt = 0;
    rep(d, 0, 10){
        s[p] = '0'+d;
        if(f(s)%10 == 0){
            ans = s;
            cnt++;
        }
    }

    if(cnt == 1) cout << ans << endl;
    else cout << "-1" << endl;
    return 0;
}