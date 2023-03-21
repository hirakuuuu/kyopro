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
// https://atcoder.jp/contests/abc048/tasks/arc064_b

int main(){
    string s; cin >> s;
    int n = s.size();
    if(n%2 == 0){
        if(s[0] != s[n-1]) cout << "Second" << endl;
        else cout << "First" << endl;
    }else{
        if(s[0] == s[n-1]) cout << "Second" << endl;
        else cout << "First" << endl;    
    }
    
    return 0;
}