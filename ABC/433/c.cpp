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
    string s; cin >> s;
    int n = (int)s.size();

    vector<ll> l(n), r(n);
    l[0] = 1;
    rep(i, 1, n){
        if(s[i-1] == s[i]){
            l[i] = l[i-1]+1;
        }else{
            l[i] = 1;
        }
    }

    r[n-1] = 1;
    rrep(i, n-2, 0){
        if(s[i] == s[i+1]){
            r[i] = r[i+1]+1;
        }else{
            r[i] = 1;
        }
    }

    ll ans = 0;
    rep(i, 0, n-1){
        // i, i+1
        if(s[i]+1 == s[i+1]){
            ans += min(l[i], r[i+1]);
        }
    }
    cout << ans << endl;
    return 0;
}