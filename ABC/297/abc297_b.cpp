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
// https://atcoder.jp/contests/abc297/tasks/abc297_b

int main(){
    string s; cin >> s;
    int b = 0, k = 0;
    vector<int> r;
    rep(i, 0, 8){
        if(s[i] == 'B') b += i;
        else if(s[i] == 'K') k = i;
        else if(s[i] == 'R') r.push_back(i);
    }

    if(b%2 and r[0] < k and k < r[1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}