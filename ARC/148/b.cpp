#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc148/tasks/arc148_b

int main(){
    int n; cin >> n;
    string s; cin >> s;

    int l = -1;
    rep(i, 0, n){
        if(s[i] == 'p'){
            l = i;
            break;
        }
    }

    if(l == -1){
        cout << s << endl;
        return 0;
    }
    
    string ans = s;

    rep(r, l, n){
        string s_;
        rep(i, 0, n){
            if(i < l or r < i) s_ += s[i];
            else{
                if(s[r-i+l] == 'd') s_ += 'p';
                else s_ += 'd';
            }
        }
        ans = min(ans, s_);
    }

    cout << ans << endl;

    
    return 0;
}