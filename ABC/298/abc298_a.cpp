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
// https://atcoder.jp/contests/abc298/tasks/abc298_a

int main(){
    int n; cin >> n;
    string s; cin >> s;
    bool f1 = false, f2 = true;
    rep(i, 0, n){
        if(s[i] == 'o') f1 = true;
        else if(s[i] == 'x') f2 = false;
    }

    if(f1 and f2) cout << "Yes" << endl;
    else cout << "No" << endl;

    
    return 0;
}