#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc245/tasks/abc245_a

int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(a < c){
        cout << "Takahashi" << endl;
    }else if(c < a){
        cout << "Aoki" << endl;
    }else if(b < d){
        cout << "Takahashi" << endl;
    }else if(d < b){
        cout << "Aoki" << endl;
    }else{
        cout << "Takahashi" << endl;
    }
    return 0;
}