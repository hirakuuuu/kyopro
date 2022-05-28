#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc002/tasks/abc002_2

int main(){
    string w; cin >> w;
    string ans;
    vector<char> b = {'a', 'i', 'u', 'e', 'o'};
    rep(i, 0, w.size()){
        bool f = true;
        rep(j, 0, b.size()){
            if(w[i] == b[j]) f = false;
        }
        if(f) ans += w[i];
    }
    cout << ans << endl;
    
    return 0;
}