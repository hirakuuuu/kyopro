#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    int n; cin >> n;
    string s; cin >> s;
    string dna = "ATCG";
    vector<vector<int>> cnt(n+1, vector<int>(4));
    int ans = 0;
    rep(i, 1, n+1){
        rep(j, 0, 4){
            if(dna[j] == s[i-1]) cnt[i][j] = cnt[i-1][j]+1;
            else cnt[i][j] = cnt[i-1][j];
        }
        rep(j, 0, i){
            if(cnt[i][0]-cnt[j][0] == cnt[i][1]-cnt[j][1] && cnt[i][2]-cnt[j][2] == cnt[i][3]-cnt[j][3]){
                ans++;
            }
        }
    }
    cout << ans << endl;


    return 0;
}