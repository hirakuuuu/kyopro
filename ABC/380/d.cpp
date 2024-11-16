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
    int q; cin >> q;
    auto f = [&](auto self, ll k) -> int{
        if(inr(0, k, n)) return 0;
        ll tmp = n;
        while(tmp <= k) tmp *= 2;

        int res = 1-self(self, k-(tmp/2));
        return res;
    };
    while(q--){
        ll k; cin >> k;
        k--;
        char c = s[k%n];
        if(islower(c)){
            if(f(f, k)&1) cout << (char)toupper(c) << ' ';
            else cout << c << ' ';
        }else{
            if(f(f, k)&1) cout << (char)tolower(c) << ' ';
            else cout << c << ' ';
        }
    }
    
    return 0;
}