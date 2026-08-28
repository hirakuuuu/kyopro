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
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c; c--;
        vector<string> s(n);
        vector<int> d(n, -1);
        rep(i, 0, n){
            cin >> s[i];
        }
        rep(i, 0, n){
            rrep(j, n-1, 0){
                if(s[j][i] == '#'){
                    d[i] = j;
                    break;
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(n));
        rep(i, 0, n) dp[i][c] = 1;

        rrep(i, n-2, 0){
            rep(j, 0, n){
                if(dp[i][j]) continue;
                int cnt = 0;
                if(j-1 >= 0 && dp[i+1][j-1]) cnt++;
                if(dp[i+1][j]) cnt++;
                if(j+1 < n && dp[i+1][j+1]) cnt++;
                if(cnt){
                    if(s[i][j] == '.'){
                        dp[i][j] = 1;
                    }else{
                        if(i == d[j]){
                            rep(k, 0, d[j]+1) dp[k][j] = 1;
                        }
                    }
                }
            }
        }

        rep(i, 0, n){
            cout << dp[0][i];
        }
        cout << endl;


    }
    
    return 0;
}