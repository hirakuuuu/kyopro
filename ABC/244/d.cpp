#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    vector<int> s(3), t(3);
    rep(i, 0, 3){
        char c; cin >> c;
        if(c == 'R') s[i] = 1;
        else if(c == 'G') s[i] = 2;
        else s[i] = 3;
    }
    rep(i, 0, 3){
        char c; cin >> c;
        if(c == 'R') t[i] = 1;
        else if(c == 'G') t[i] = 2;
        else t[i] = 3;
    }
    int tens = 0, tent = 0;
    rep(i, 0, 3){
        rep(j, i+1, 3){
            if(s[j] < s[i]) tens++;
            if(t[j] < t[i]) tent++;
        }
    }
    if(tens%2 == tent%2) cout << "Yes" << endl;
    else cout << "No" << endl;

  
}