#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc033/tasks/agc033_b

int main(){
    ll h, w, n; cin >> h >> w >> n;
    ll sr, sc; cin >> sr >> sc;
    string s, t; cin >> s >> t;

    vector<char> dir = {'U', 'L', 'D', 'R'};    
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, -1, 0, 1};


    ll pr = sr, pc = sc;
    rep(i, 0, n){
        if(s[i] == 'L') pc--;
        if(pc == 0){
            cout << "NO" << endl;
            return 0;
        }
        if(t[i] == 'R') pc = min(pc+1, w);
    }
    pr = sr, pc = sc;
    rep(i, 0, n){
        if(s[i] == 'R') pc++;
        if(pc == w+1){
            cout << "NO" << endl;
            return 0;
        }
        if(t[i] == 'L') pc = max(pc-1, 1LL);
    }
    pr = sr, pc = sc;
    rep(i, 0, n){
        if(s[i] == 'U') pr--;
        if(pr == 0){
            cout << "NO" << endl;
            return 0;
        }
        if(t[i] == 'D') pr = min(pr+1, h);
    }
    pr = sr, pc = sc;
    rep(i, 0, n){
        if(s[i] == 'D') pr++;
        if(pr == h+1){
            cout << "NO" << endl;
            return 0;
        }
        if(t[i] == 'U') pr = max(pr-1, 1LL);
    }

    cout << "YES" << endl;

    
    return 0;
}