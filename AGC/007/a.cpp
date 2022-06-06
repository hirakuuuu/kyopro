#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc007/tasks/agc007_a

int main(){
    int h, w; cin >> h >> w;
    int cnt = 0;
    rep(i, 0, h){
        rep(j, 0, w){
            char c; cin >> c;
            if(c == '#'){
                cnt++;
            }
        }
    }
    if(cnt == h+w-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    
    return 0;
}