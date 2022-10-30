#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n; cin >> n;
    ll x; cin >> x;
    string s; cin >> s;
    stack<char> stc;
    stc.push(s[0]);
    rep(i, 1, n){
        if(stc.size() and stc.top() != 'U' and s[i] == 'U'){
            stc.pop();
        }else stc.push(s[i]);
    }
    string t;
    while(!stc.empty()){
        char ss = stc.top(); stc.pop();
        t += ss;
    }
    reverse(t.begin(), t.end());

    ll ans = x;
    for(auto tt: t){
        if(tt == 'L') ans *= 2;
        else if(tt == 'U') ans /= 2;
        else ans = 2*ans+1;
    }

    cout << ans << endl;
}