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
// https://atcoder.jp/contests/abc321/tasks/abc321_c

// int main(){
//     ll K; cin >> K;

//     if(K <= 9){
//         cout << K << endl;
//         return 0;
//     }

//     vector<vector<ll>> cnt(20, vector<ll>(10));
//     vector<ll> sum(20);
//     cnt[0][0] = cnt[1][0] = 1;
//     sum[1]--;
//     rep(i, 1, 11){
//         rep(j, 0, 10){
//             rep(k, 0, j){
//                 cnt[i][j] += cnt[i-1][k];
//             }
//             sum[i] += cnt[i][j];
//         }
//         //cout << i << ' ' << sum[i] << endl;
//     }

//     // 桁
//     ll o = 0, tmp = K;
//     rep(i, 1, 11){
//         tmp -= sum[i];
//         if(tmp <= 0){
//             o = i;
//             break;
//         }
//     }

//     ll ans = 0, r = 10, cur = 0;
//     tmp = K;
//     rrep(i, o, 1){
//         if(i == o) rep(j, 1, i) tmp -= sum[j];
//         rep(j, 0, r){
//             tmp -= cnt[i][j];
//             if(tmp <= 0){
//                 tmp += cnt[i][j];
//                 ans += j*pow(10, i-1);
//                 r = j;
//                 break;
//             }
//         }
//     }

//     cout << ans << endl;



    
//     return 0;
// }

int main(){
    ll K; cin >> K;
    vector<ll> ans;
    rep(i, 1, (1<<10)){
        vector<ll> bit;
        rep(j, 0, 10){
            if((i&(1<<j)) > 0) bit.push_back(j);
        }
        sort(bit.begin(), bit.end());
        ll tmp = 0;
        rep(j, 0, bit.size()){
            tmp += bit[j]*pow(10, j);
        }
        ans.push_back(tmp);
    }
    sort(ans.begin(), ans.end());
    cout << ans[K] << endl;
    return 0;
}