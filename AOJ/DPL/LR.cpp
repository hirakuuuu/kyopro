#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
最大長方形問題　ヒストグラムで解く
*/
int main(){
    int h, w; cin >> h >> w;
    vector<vector<int>> c(h, vector<int>(w+1));
    rep(i, 0, h){
        rep(j, 0, w){
            int C; cin >> C;
            if(i == 0){
                if(C == 0) c[i][j] = 1;
                else c[i][j] = 0;
            }else{
                if(C == 0) c[i][j] = c[i-1][j]+1;
                else c[i][j] = 0;
            }
        }
    }
    int ans = 0;
    rep(i, 0, h){
        stack<pii> stc;
        int max_area = 0;
        rep(j, 0, w+1){
            if(stc.empty()) stc.push({c[i][j], j});
            else{
                if(stc.top().first > c[i][j]){
                    int l = j;
                    while(!stc.empty() and stc.top().first > c[i][j]){
                        pii s = stc.top(); stc.pop();
                        max_area = max(max_area, s.first*(j-s.second));
                        l = s.second;
                    }
                    stc.push({c[i][j], l});
                }else if(stc.top().first < c[i][j]) stc.push({c[i][j], j});
            }
        }
        ans = max(max_area, ans);
    }
    cout << ans << endl;



}