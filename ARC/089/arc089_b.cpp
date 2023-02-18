#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc086/tasks/arc089_b

int main(){
    int n, k; cin >> n >> k;
    vector<vector<int>> cnt(k+1, vector<int>(k+1));

    rep(i, 0, n){
        int x, y; cin >> x >> y;
        char c; cin >> c;

        if((((x/k)%2)^((y/k)%2)) == 0){
            // (x, y) は白
            int pos_x = k-1-y%k;
            int pos_y = k-1-x%k;
            if(c == 'W'){
                // 左下
                cnt[0][0]++;
                cnt[pos_x+1][0]--;
                cnt[0][pos_y+1]--;
                cnt[pos_x+1][pos_y+1]++;
                // 右上
                cnt[pos_x+1][pos_y+1]++;
                cnt[pos_x+1][k]--;
                cnt[k][pos_y+1]--;
                cnt[k][k]++;
            }else{
                // 左上
                cnt[0][pos_y+1]++;
                cnt[0][k]--;
                cnt[pos_x+1][pos_y+1]--;
                cnt[pos_x+1][k]++;
                // 右下
                cnt[pos_x+1][0]++;
                cnt[k][0]--;
                cnt[pos_x+1][pos_y+1]--;
                cnt[k][pos_y+1]++;
            }
        }else{
            // (x, y) は黒
            int pos_x = k-1-y%k;
            int pos_y = k-1-x%k;
            if(c == 'B'){
                // 左下
                cnt[0][0]++;
                cnt[pos_x+1][0]--;
                cnt[0][pos_y+1]--;
                cnt[pos_x+1][pos_y+1]++;
                // 右上
                cnt[pos_x+1][pos_y+1]++;
                cnt[pos_x+1][k]--;
                cnt[k][pos_y+1]--;
                cnt[k][k]++;
            }else{
                // 左上
                cnt[0][pos_y+1]++;
                cnt[0][k]--;
                cnt[pos_x+1][pos_y+1]--;
                cnt[pos_x+1][k]++;
                // 右下
                cnt[pos_x+1][0]++;
                cnt[k][0]--;
                cnt[pos_x+1][pos_y+1]--;
                cnt[k][pos_y+1]++;
            }
        }
    }

    rep(i, 0, k+1){
        rep(j, 0, k){
            cnt[i][j+1] += cnt[i][j];
        }
    }
    rep(i, 0, k+1){
        rep(j, 0, k){
            cnt[j+1][i] += cnt[j][i];
        }
    }

    int ans = 0;
    rep(i, 0, k){
        rep(j, 0, k) chmax(ans, max(cnt[i][j], n-cnt[i][j]));
    }
    cout << ans << endl;
    
    return 0;
}