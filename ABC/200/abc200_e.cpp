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
// https://atcoder.jp/contests/abc200/tasks/abc200_e

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> ans(3);
    vector<ll> cnt_2(3*n+1);
    cnt_2[2] = 1;
    rep(i, 3, 2*n+1){
        if(i-1 <= n) cnt_2[i] = i-1;
        else cnt_2[i] = 2*n-i+1;
    }
    vector<ll> sum_cnt_2(3*n+1);
    rep(i, 2, 3*n+1){
        sum_cnt_2[i] = sum_cnt_2[i-1]+cnt_2[i];
    }

    vector<ll> cnt(3*n+1);
    ll tmp_sum = 0;
    rep(i, 3, 3*n+1){
        cnt[i] = sum_cnt_2[i-1]-sum_cnt_2[max(0LL, i-n-1)];
        if(k > cnt[i]) k-= cnt[i];
        else{
            tmp_sum = i;
            break;
        }
    }
    // 合計値がtmp_sumでk番目のものを見つける
    rep(i, 1, n+1){
        if(tmp_sum-i < 2 || 2*n < tmp_sum-i) continue;
        if(k > cnt_2[tmp_sum-i]) k -= cnt_2[tmp_sum-i];
        else{
            ans[0] = i;
            tmp_sum -= i;
            break;
        }
    }
    rep(i, 1, n+1){
        if(tmp_sum-i < 1 || n < tmp_sum-i) continue;
        if(k > 1) k --;
        else{
            ans[1] = i;
            ans[2] = tmp_sum-i;
            break;
        }
    }

    rep(i, 0, 3){
        cout << ans[i] << ' ';
    }
    cout << endl;







    return 0;
}