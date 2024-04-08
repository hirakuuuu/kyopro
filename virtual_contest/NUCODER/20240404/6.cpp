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
    int n, k, c; cin >> n >> k >> c;
    string s; cin >> s;
    vector<pair<int, int>> dp_l(n+1);
    dp_l[0] = {0, -IINF};
    rep(i, 1, n+1){
        if(s[i-1] == 'o'){
            if(dp_l[i-1].second+c < i){
                dp_l[i] = {dp_l[i-1].first+1, i};
            }else{
                dp_l[i] = dp_l[i-1];
            }
        }else{
            dp_l[i] = dp_l[i-1];
        }
    }
    vector<pair<int, int>> dp_r(n+2);
    dp_r[n+1] = {0, IINF};
    rrep(i, n, 1){
        if(s[i-1] == 'o'){
            if(i+c < dp_r[i+1].second){
                dp_r[i] = {dp_r[i+1].first+1, i};
            }else{
                dp_r[i] = dp_r[i+1];
            }
        }else{
            dp_r[i] = dp_r[i+1];
        }
        // cout << i << ' ' << dp_r[i].first << ' ' << dp_r[i].second << endl;
    }
    rep(i, 1, n+1){
        if(s[i-1] == 'o'){
            int tmp = dp_l[i-1].first;
            if(dp_l[i-1].second == -IINF){
                tmp += dp_r[i+1].first;
            }else{
                int start = max(dp_l[i-1].first+c+1, i+1);
                if(start <= n) tmp += dp_r[start].first;
            }
            if(tmp == k-1){
                cout << i << endl;
            }
        }
    }
    return 0;
}