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
// https://atcoder.jp/contests/abc291/tasks/abc291_f

/*
１からの最短距離を求める
kを飛ばすということはk-10→k+10みたいな移動をするということ
*/

vector<vector<int>> g(100005);

int main(){
    int n, m; cin >> n >> m;
    vector<string> s(n+1), t(n);
    rep(i, 1, n+1){
        cin >> s[i];
        rep(j, 1, m+1){
            if(s[i][j-1] == '1'){
                g[j+i].push_back(i);
            }
        }
    }

    vector<int> dp_l(n+1, iinf);
    vector<int> dp_r(n+1, iinf);
    dp_l[1] = 0;
    rep(i, 1, n+1){
        rep(j, 1, m+1){
            if(s[i][j-1] == '1'){
                chmin(dp_l[i+j], dp_l[i]+1);
            }
        }
    }

    dp_r[n] = 0;
    rrep(i, n, 1){
        for(const auto &to: g[i]){
            chmin(dp_r[to], dp_r[i]+1);
        }
    }

    vector<int> ans(n+1, iinf);

    rep(k, 2, n){
        rep(i, k-m+1, k){
            if(i < 1) continue;
            rep(j, k+1, i+m+1){
                if(n < j) continue;
                if(s[i][j-i-1] == '1'){
                    chmin(ans[k], dp_l[i]+dp_r[j]+1);
                }
            }
        }
    }

    rep(i, 2, n){
        if(ans[i] == iinf)cout << -1 << ' ';
        else cout << ans[i] << ' ';
    }
    cout << endl;



    
    return 0;
}