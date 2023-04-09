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
// https://atcoder.jp/contests/abc297/tasks/abc297_c

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    rep(i, 0, h){
        rep(j, 0, w-1){
            if(s[i][j] == 'T' and s[i][j+1] == 'T'){
                s[i][j] = 'P';
                s[i][j+1] = 'C';
            }
        }
        cout << s[i] << endl;
    }
    
    return 0;
}