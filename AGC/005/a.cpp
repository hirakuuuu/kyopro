#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc005/tasks/agc005_a

int main(){
    string x; cin >> x;
    int n = x.size();
    vector<int> s = {0}, t = {0};
    rep(i, 0, n){
        int cnt = 0, j = i;
        while(x[j] == x[i]) cnt++, i++;
        if(x[j] == 'S') s.push_back(cnt);
        else t.push_back(cnt);
        i--;
    }
    s.push_back(0), t.push_back(0);

    bool f = (x[0] == 'T');
    int si = 1, ti = 1+f, decrease = 0;
    while(ti < t.size() and si < s.size()){
        decrease += 2*min(s[si], t[ti]);
        if(s[si] >= t[ti]){
            s[si] -= t[ti];
            s[si+1] += s[si];
        }
        si++;
        ti++;
    }
    cout << n-decrease << endl;

    
    return 0;
}