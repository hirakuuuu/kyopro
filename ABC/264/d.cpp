#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc264/tasks/abc264_d

int main(){
    string s; cin >> s;
    string atcoder = "atcoder";
    int ans = 0;

    rep(i, 0, 7){
        int pos = 0;
        rep(j, 0, 7){
            if(s[j] == atcoder[i]){
                pos = j;
                break;
            }
        }

        for(int j = pos; j > i; j--){
            swap(s[j], s[j-1]);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}