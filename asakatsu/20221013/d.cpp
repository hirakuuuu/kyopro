#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/apc001/tasks/apc001_c

int main(){
    int n; cin >> n;
    vector<string> mw(n);
    string s;

    cout << 0 << endl; cin >> s;
    if(s == "Vacant") return 0;
    mw[0] = s;

    cout << n-1 << endl; cin >> s;
    if(s == "Vacant") return 0;
    mw[n-1] = s;
    
    int l = 0, r = n-1;
    while(true){
        int m = (l+r)/2;
        cout << m << endl; cin >> s;
        if(s == "Vacant") return 0;
        mw[m] = s;
        if((m-l)%2 == 0 and mw[l] != mw[m]) r = m;
        else if((m-l)%2 == 1 and mw[l] == mw[m]) r = m;
        else if((r-m)%2 == 0 and mw[r] != mw[m]) l = m;
        else if((r-m)%2 == 1 and mw[r] == mw[m]) l = m;   
    }
    
    return 0;
}