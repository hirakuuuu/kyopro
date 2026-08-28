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
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    ll m = 998244353;
    ll ans = 0;
    for(int i = 0; i < n; ){
        if(i == n-1){
            ans += 1;
            ans %= m;
            break;
        }

        int j = i;
        while(j < n-1 && s[j] != s[j+1]) j++;
        ll len = j-i+1;
        ans += len*(len+1)/2;
        ans %= m;
        i = j+1;
    }
    cout << ans << endl;
    return 0;
}