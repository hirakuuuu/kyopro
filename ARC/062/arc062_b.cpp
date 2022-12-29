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
// https://atcoder.jp/contests/abc046/tasks/arc062_b

int main(){
    string s; cin >> s;
    int ans = 0, p = 0;
    rep(i, 0, s.size()){
        if(s[i] == 'g'){
            if(p > 0){
                ans++, p--;
            }else{
                p++;
            }
        }else{
            if(p > 0){
                p--;
            }else{
                ans--, p++;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}