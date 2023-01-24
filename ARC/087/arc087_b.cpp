#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc087/tasks/arc087_b

/*置き換えはswapでやる*/

int main(){
    string s; cin >> s;
    int n = (int) s.size();
    int x, y; cin >> x >> y;
    vector<int> dx, dy;
    int d = 0;
    rep(i, 0, n){
        if(s[i] == 'T') d = 1-d;
        else{
            int cnt = 0;
            while(i < n and s[i] == 'F'){
                cnt++;
                i++;
            }
            if(d == 0) dx.push_back(cnt);
            else dy.push_back(cnt);
            d = 1-d;
        }
    }

    

  	vector<vector<int>> dp_x(4005, vector<int>(8005));
  	vector<vector<int>> dp_y(4005, vector<int>(8005));

    vector<int> can_x;
    int lx = 0, bx = 0;
    dp_x[0][0] = 1;
    if(s[0] == 'F'){
        dp_x[1][0] = 1;
        bx = dx[0];
        lx++;
    }
    rep(i, lx, (int) dx.size()){
        rep(j, 0, 8005){
            if(dp_x[i][j]){
                dp_x[i+1][abs(j+dx[i])] = 1;
                dp_x[i+1][abs(j-dx[i])] = 1;
            }
        }
    }
    dp_y[0][0] = 1;
    rep(i, 0, (int) dy.size()){
        rep(j, 0, 8005){
            if(dp_y[i][j]){
                dp_y[i+1][abs(j+dy[i])] = 1;
                dp_y[i+1][abs(j-dy[i])] = 1;
            }
        }
    }
    // cout << dp_x[dx.size()][x-bx] << endl;
    // cout << dp_y[dy.size()][abs(y)] << endl;
    if(x >= bx and dp_x[dx.size()][x-bx] and dp_y[dy.size()][abs(y)]) cout << "Yes" << endl;
    else if(x < bx and dp_x[dx.size()][bx-x] and dp_y[dy.size()][abs(y)]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}