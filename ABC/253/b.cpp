#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc253/tasks/abc253_b

int main(){
    int h, w; cin >> h >> w;
    int sh = -1, sw = -1, th = -1, tw = -1;
    rep(i, 0, h){
        rep(j, 0, w){
            char c; cin >> c;
            if(c == 'o' and sh == -1){
                sh = i, sw = j;
            }else if(c == 'o'){
                th = i, tw = j;
            }
        }
    }
    
    cout << abs(sh-th)+abs(sw-tw) << endl;
    
    return 0;
}