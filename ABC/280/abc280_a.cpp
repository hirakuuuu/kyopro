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
// https://atcoder.jp/contests/abc280/tasks/abc280_a

int main(){
    int h, w; cin >> h >> w;
    int ans = 0;
    rep(i, 0, h){
        string s; cin >> s;
        rep(j, 0, w){
            if(s[j] == '#') ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}