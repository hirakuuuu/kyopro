#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc258/tasks/abc258_a

int main(){
    int k; cin >> k;
    if(k >= 60){
        cout << "22:";
    }else{
        cout << "21:";
    }

    if(k%60 < 10){
        cout << '0' << k%60 << endl;
    }else{
        cout << k%60 << endl;
    }
    
    return 0;
}