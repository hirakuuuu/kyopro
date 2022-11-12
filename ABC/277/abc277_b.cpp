#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc277/tasks/abc277_b

int main(){
    int n; cin >> n;
    map<char, int> k;
    k['H'] = 1;
    k['D'] = 2;
    k['C'] = 3;
    k['S'] = 4;
    map<char, int> c;
    c['A'] = 1;
    c['2'] = 2;
    c['3'] = 3;
    c['4'] = 4;
    c['5'] = 5;
    c['6'] = 6;
    c['7'] = 7;
    c['8'] = 8;
    c['9'] = 9;
    c['T'] = 10;
    c['J'] = 11;
    c['Q'] = 12;
    c['K'] = 13;


    vector<vector<bool>> seen(5, vector<bool>(14));

    bool f = true;

    rep(i, 0, n){
        string s; cin >> s;
        if(k[s[0]] == 0 or c[s[1]] == 0 or seen[k[s[0]]][c[s[1]]]){
            f = false;
        }else{
            seen[k[s[0]]][c[s[1]]] = true;
        }
    }

    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;


    
    return 0;
}