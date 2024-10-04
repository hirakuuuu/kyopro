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
    string RPS = "RPS";
    map<char, int> id;
    id['R'] = 0;
    id['P'] = 1;
    id['S'] = 2;
    vector<int> dp(3);
    rep(i, 0, n){
        int aoki = id[s[i]];
        vector<int> dp_(3);
        rep(j, 0, 3){
            if((aoki+2)%3 == j) continue;
            if(aoki == j) chmax(dp_[j], max(dp[(j+1)%3], dp[(j+2)%3]));
            else chmax(dp_[j], max(dp[(j+1)%3], dp[(j+2)%3])+1);
        }
        swap(dp_, dp);
    }
    cout << max({dp[0], dp[1], dp[2]}) << endl;

    
    return 0;
}