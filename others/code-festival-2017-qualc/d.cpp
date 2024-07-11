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
    vector<int> acc(n+1);
    rep(i, 0, n){
        int tmp = s[i]-'a';
        acc[i+1] = (acc[i]^(1<<tmp));
    } 
    map<int, int> dp;
    dp[0] = 0;
    rep(i, 1, n+1){
        if(__popcount(acc[i]) <= 1){
            dp[acc[i]] = 1;
        }else{
            int mi = dp[acc[i-1]]+1;
            rep(j, 0, 26){
                int tmp = (acc[i]^(1<<j));
                if(dp.find(tmp) != dp.end()){
                    chmin(mi, dp[tmp]+1);
                }
            }
            dp[acc[i]] = mi;
        }
    }
    cout << dp[acc[n]] << endl;

    
    return 0;
}