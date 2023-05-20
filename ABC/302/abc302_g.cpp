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
// https://atcoder.jp/contests/abc302/tasks/abc302_g

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    vector<vector<int>> cnt(5, vector<int>(5));
    vector<int> pos(5);
    rep(i, 0, n) pos[a[i]]++;
    rep(i, 0, 4) pos[i+1] += pos[i];

    rep(i, 1, 5){
        rep(j, pos[i-1], pos[i]){
            cnt[i][a[j]]++;
        }
    }
    int ans = 0;
    rep(i, 1, 4){
        rep(j, i+1, 5){
            if(cnt[i][j] <= cnt[j][i]){
                ans += cnt[i][j];
                cnt[i][i] += cnt[i][j];
                cnt[j][j] += cnt[i][j];
                cnt[j][i] -= cnt[i][j];
                cnt[i][j] = 0;
            }else{
                ans += cnt[j][i];
                cnt[i][i] += cnt[j][i];
                cnt[j][j] += cnt[j][i];
                cnt[i][j] -= cnt[j][i];
                cnt[j][i] = 0;  
            }
        }
        rep(j, i+1, 5){
            if(cnt[j][i] > 0){
                rep(k, i+1, 5){
                    if(cnt[i][k] > 0){
                        if(cnt[i][k] <= cnt[j][i]){
                            ans += cnt[i][k];
                            cnt[i][i] += cnt[i][k];
                            cnt[j][k] += cnt[i][k];
                            cnt[j][i] -= cnt[i][k];
                            cnt[i][k] = 0;
                        }else{
                            ans += cnt[j][i];
                            cnt[i][i] += cnt[j][i];
                            cnt[j][k] += cnt[j][i];
                            cnt[i][k] -= cnt[j][i];
                            cnt[j][i] = 0;  
                        }
                    }
                }
            }
        }
        // rep(j, 1, 5){
        //     rep(k, 1, 5){
        //         cout << cnt[j][k] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    cout << ans << endl;




    
    return 0;
}