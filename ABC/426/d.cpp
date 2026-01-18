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
        int n; cin >> n;
        string s; cin >> s;
        vector<pair<int, int>> rl;
        for(int i = 0; i < n; ){
            int j = i;
            while(j < n && s[i] == s[j]){
                j++;
            }
            rl.emplace_back(i, j-i);
            i = j;
        }

        vector<vector<int>> acc(2, vector<int>(n+1));
        rep(i, 0, n){
            acc[0][i+1] = acc[0][i]+(s[i]=='0');
            acc[1][i+1] = acc[1][i]+(s[i]=='1');
        }

        int ans = IINF;
        for(auto [l, len]: rl){
            int r = l+len;
            char c = s[l];
            int cnt_l, cnt_r;
            if(c == '0'){
                cnt_l = (acc[0][l]-acc[0][0])*2+(acc[1][l]-acc[1][0]);
                cnt_r = (acc[0][n]-acc[0][r])*2+(acc[1][n]-acc[1][r]);
            }else{
                cnt_l = (acc[1][l]-acc[1][0])*2+(acc[0][l]-acc[0][0]);
                cnt_r = (acc[1][n]-acc[1][r])*2+(acc[0][n]-acc[0][r]);
            }
            chmin(ans, cnt_l+cnt_r);
        }
        cout << ans << endl;
    }
    
    return 0;
}