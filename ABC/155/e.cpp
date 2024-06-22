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
    string s; cin >> s;
    int n = (int)s.size();
    reverse(s.begin(), s.end());

    vector<vector<int>> memo(n+1, vector<int>(2, -1));
    auto f = [&](auto self, int pos, int c) -> int {
        if(memo[pos][c] != -1) return memo[pos][c];
        if(pos == n) return memo[pos][c] = c;
        int tmp = (s[pos]-'0')+c;
        return memo[pos][c] = min(tmp+self(self, pos+1, 0), 10-tmp+self(self, pos+1, 1));
    };
    cout << f(f, 0, 0) << endl;
    
    return 0;
}