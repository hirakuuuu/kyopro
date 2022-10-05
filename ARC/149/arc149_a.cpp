#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc149/tasks/arc149_a

int main(){
    ll n, m; cin >> n >> m;
    string int_char = "0123456789";
    

    vector<string> ans(10);
    vector<int> amari(10);
    rep(i, 1, 10){
        ans[i] += int_char[i];
        amari[i] = i%m;
    }

    string ans_str = "-1";

    rep(i, 0, n){
        rep(j, 1, 10){
            if(amari[j] == 0){
                ans_str = ans[j];
            }
            ans[j] += int_char[j];
            amari[j] = (amari[j]*10+j)%m;
        }
    }

    cout << ans_str << endl;

    
    return 0;
}