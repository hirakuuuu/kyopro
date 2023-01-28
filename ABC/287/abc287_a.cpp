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
// https://atcoder.jp/contests/abc287/tasks/abc287_a

int main(){
    int n; cin >> n;
    vector<string> s(n);
    int ans = 0;
    rep(i, 0, n){
        cin >> s[i];
        if(s[i] == "For") ans++;
    } 

    if(ans > n/2) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}