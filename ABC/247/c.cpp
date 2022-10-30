#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc247/tasks/abc247_c

int main(){
    int n; cin >> n;
    vector<int> s;
    rep(i, 0, n){
        vector<int> t = s;
        reverse(t.begin(), t.end());
        vector<int> u;
        rep(i, 0, t.size()) u.push_back(t[i]);
        u.push_back(i+1);
        rep(i, 0, s.size()) u.push_back(s[i]);
        s = u;
    }

    rep(i, 0, s.size()){
        if(i > 0) cout << " ";
        cout << s[i];
    }
    cout << endl;
    
    return 0;
}