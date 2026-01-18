#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string s; cin >> s;
    int n = (int)s.size();

    int cnt_q = 0;
    rep(i, 0, n){
        if(s[i] == '?') cnt_q++;
    }

    unordered_map<char, int> id;
    rep(i, 0, 26){
        char c = 'a'+i;
        id[c] = i;
        char d = 'A'+i;
        id[d] = i+26;
    }

    vector<vector<mint>> dp(52, vector<mint>(4));
    if(s[0] == '?'){
        rep(i, 0, 26) dp[i][0] = 1; 
        rep(i, 26, 52) dp[i][1] = 1; 
    }else if(islower(s[0])){
        dp[id[s[0]]][0] = 1;
    }else{
        dp[id[s[0]]][1] = 1;
    }
    mint ans = mint(52).pow(cnt_q);

    rep(i, 1, n){
        vector<vector<mint>> ndp(52, vector<mint>(4));
        vector<mint> tot(4);
        rep(j, 0, 52){
            rep(k, 0, 4){
                tot[k] += dp[j][k];
            }
        }
        rep(k, 0, 4){
            cout << tot[k].val() << ' ';
        }

        cout << endl;

        if(s[i] == '?'){
            cnt_q--;
            rep(j, 0, 26){
                ndp[j][0] += tot[0]+tot[1]+tot[3];
                ndp[j][3] += tot[2];
            }
            rep(j, 26, 52){
                ndp[j][1] += tot[0]+(tot[1]-dp[j][1])+(tot[2]-dp[j][2])+tot[3];
                ndp[j][2] += dp[j][1]+dp[j][2];
            }
            ans -= tot[3]*26*(mint(52).pow(cnt_q));
        }else if(isupper(s[i])){
            int j = id[s[i]];
            ndp[j][1] += tot[0]+(tot[1]-dp[j][1])+(tot[2]-dp[j][2])+tot[3];
            ndp[j][2] += dp[j][1]+dp[j][2];
            ans -= tot[3]*(mint(52).pow(cnt_q));
        }else{
            int j = id[s[i]];
            ndp[j][0] += tot[0]+tot[1]+tot[3];
            ndp[j][3] += tot[2];
        }
        swap(ndp, dp);

    }
    cout << ans.val() << endl;
    
    return 0;
}