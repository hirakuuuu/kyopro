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
// https://atcoder.jp/contests/abc287/tasks/abc287_d

int main(){
    string s, t; cin >> s >> t;

    vector<bool> sf((int)t.size()+1);
    vector<bool> sl((int)t.size()+1);
    sf[0] = true;
    sl[0] = true;

    rep(i, 1, (int) t.size()+1){
        if(!sf[i-1]) continue;
        if(s[i-1] == '?' or t[i-1] == '?' or s[i-1] == t[i-1]) sf[i] = true;
    }
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    rep(i, 1, (int) t.size()+1){
        if(!sl[i-1]) continue;
        if(s[i-1] == '?' or t[i-1] == '?' or s[i-1] == t[i-1]) sl[i] = true;
    }

    rep(i, 0, (int) t.size()+1){
        if(sf[i] and sl[t.size()-i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}