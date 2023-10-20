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
    int n, k; cin >> n >> k;
    vector<vector<int>> cnt(n, vector<int>(26));
    rep(i, 0, n){
        string s; cin >> s;
        for(auto ss: s){
            cnt[i][ss-'a']++;
        }
    }

    ll ans = 0;
    rep(i, 0, 1<<n){
        vector<int> tmp(26);
        rep(j, 0, n){
            if((i&(1<<j)) > 0){
                rep(k, 0, 26) tmp[k] += (cnt[j][k] > 0);
            }
        }

        int sum = 0;
        rep(j, 0, 26) sum += (tmp[j] == k);
        chmax(ans, sum);
        
    }

    cout << ans << endl;


    

    return 0;
}