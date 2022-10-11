#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc056/tasks/agc056_a

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n){
        rep(j, 0, n) s[i] += '.';
    }

    int pos = 0;
    rep(i, 0, n){
        int bias = 0;
        if(n-pos == 1) bias = -1;
        else if(n-pos == 2) bias = 1;

        rep(j, 0, 3){
            s[i][(pos+bias+n)%n] = '#';
            pos++;
            pos %= n;
        }
    }

    rep(i, 0, n){
        rep(j, 0, n){
            cout << s[i][j];
        }
        cout << endl;
    }
    
    return 0;
}