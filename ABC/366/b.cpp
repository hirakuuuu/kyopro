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
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    int m = 0;
    rep(i, 0, n) chmax(m, s[i].size());
    vector<string> t(m);
    rrep(i, n-1, 0){
        rep(j, 0, s[i].size()){
            t[j].push_back(s[i][j]);
        }
        rep(j, s[i].size(), m){
            t[j].push_back('*');
        }
    }
    // 末尾の * を消す
    rep(j, 0, m){
        while(!t[j].empty() && t[j].back() == '*') t[j].pop_back();
    }
    rep(j, 0, m){
        cout << t[j] << endl;
    }

    
    return 0;
}