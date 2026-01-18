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
    map<int, bool> memo;
    auto f = [&](auto self, int n) -> bool {
        if(memo.count(n)) return n == 1;
        memo[n] = true;
        string s = to_string(n);
        int nxt = 0;
        for(auto ss: s) nxt += (ss-'0')*(ss-'0');
        bool res = self(self, nxt);
        return res;
    };

    int n; cin >> n;
    if(f(f, n)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}