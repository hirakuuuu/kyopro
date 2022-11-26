#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc279/tasks/abc279_c

int main(){
    int h, w; cin >> h >> w;
    map<string, int> m;
    vector<string> s(h);
    rep(i, 0, h){
        cin >> s[i];
    }
    rep(i, 0, w){
        string c;
        rep(j, 0, h){
            c += s[j][i];
        }
        m[c]++;
    }

    vector<string> t(h);
    rep(i, 0, h){
        cin >> t[i];
    }
    rep(i, 0, w){
        string c;
        rep(j, 0, h){
            c += t[j][i];
        }
        m[c]--;
    }

    for(auto mm: m){
        if(mm.second < 0){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    
    
    return 0;
}