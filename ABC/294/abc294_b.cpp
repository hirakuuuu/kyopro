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
// https://atcoder.jp/contests/abc294/tasks/abc294_b

int main(){
    int h, w; cin >> h >> w;
    rep(i, 0, h){
        string s;
        rep(j, 0, w){
            int a; cin >> a;
            if(a == 0) s += '.';
            else s += 'A'+a-1;
        }
        cout << s << endl;
    }
    
    return 0;
}