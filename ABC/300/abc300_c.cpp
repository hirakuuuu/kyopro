#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc300/tasks/abc300_c

vector<int> dh={-1, -1, 1, 1};
vector<int> dw={-1, 1, -1, 1};

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    vector<int> ans(min(h, w)+1);
    rep(i, 0, h){
        rep(j, 0, w){
            // 4方向に＃があるか
            if(s[i][j] == '.') continue;
            int cnt = 0, d = 1;
            while(true){
                cnt = 0;
                rep(k, 0, 4){
                    if(i+d*dh[k] >= 0 and i+d*dh[k] < h and  j+d*dw[k] >= 0 and j+d*dw[k] < w and s[i+d*dh[k]][j+d*dw[k]] == '#'){
                        cnt++;
                    }
                }
                if(cnt == 4) d++;
                else break;
            }
            ans[d-1]++;
        }
    }
    
    rep(i, 1, min(h, w)+1) cout << ans[i] << ' ';
    cout << endl;




    
    return 0;
}