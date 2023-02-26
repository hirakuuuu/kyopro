#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc291/tasks/abc291_c

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int x = 0, y = 0;
    map<pii, bool> seen;
    seen[{x, y}] = true;
    string d = "LDRU";
    rep(i, 0, n){
        rep(j, 0, 4){
            if(s[i] == d[j]){
                x += (j-1)%2;
                y += (j-2)%2;
                break;
            }
        }
        if(seen[{x, y}]){
            cout << "Yes" << endl;
            return 0;
        }
        seen[{x, y}] = true;
    }
    cout << "No" << endl;
    
    return 0;
}