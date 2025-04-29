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
    int T; cin >> T;
    while(T--){
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        ll c = max(0LL, (k+2*n-1)/(2*n));
        if(c%2) reverse(s.begin(), s.end());
        k %= 2*n;
        string s_(k, '#');
        rep(i, 0, min(k, n)) s_[i] = s[n-1-i];
        rrep(i, k-1, max(0LL, k-n)) s_[i] = s[k-1-i];

        auto is_palindrome = [&](string t) -> bool {
            int m = (int)t.size();
            rep(i, 0, m){
                if(t[i] != t[m-1-i]) return false;
            }
            return true;
        };
        if(is_palindrome(s+s_) && is_palindrome(s_+s)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}