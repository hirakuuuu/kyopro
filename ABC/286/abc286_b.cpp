#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc286/tasks/abc286_b

int main(){
    int n; cin >> n;
    string s; cin >> s;
    string ans;
    rep(i, 0, n){
        if(i < n-1 and s[i] == 'n' and s[i+1] == 'a'){
            ans += 'n';
            ans += 'y';
            ans += 'a';
            i++;
        }else{
            ans += s[i];
        }
    }
    cout << ans << endl;
    
    return 0;
}