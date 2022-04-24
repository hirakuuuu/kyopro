#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc249/tasks/abc249_b

int main(){
    string s; cin >> s;
    bool f1 = false, f2 = false, f3 = true;
    map<char, int> m;
    for(auto ss: s){
        if(0 <= ss-'A' and 0 <= 'Z'-ss) f1 = true;
        if(0 <= ss-'a' and 0 <= 'z'-ss) f2 = true;
        if(m[ss]) f3 = false;
        m[ss] = 1;
    }
    if(f1 and f2 and f3){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }    
    return 0;
}