#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc260/tasks/abc260_a

int main(){
    string s; cin >> s;
    vector<int> count(26);

    rep(i, 0, 3){
        count[s[i]-'a']++;
    }

    rep(j, 0, 26){
        if(count[j] == 1){
            char c = j+'a';
            cout << c << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    
    return 0;
}