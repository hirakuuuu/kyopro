#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc219/tasks/abc219_c

int main(){
    string x; cin >> x;
    int n; cin >> n;
    vector<vector<int>> s(n);
    map<char, int> change;
    rep(i, 0, 26){
        change[x[i]] = i;
    }
    rep(i, 0, n){
        string t; cin >> t;
        for(auto tt: t){
            s[i].push_back(change[tt]);
        }
    }

    sort(s.begin(), s.end());

    rep(i, 0, n){
        for(auto ss: s[i]){
            cout << x[ss];
        }
        cout << endl;
    }
    
    return 0;
}