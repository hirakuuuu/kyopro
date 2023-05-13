#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc301/tasks/abc301_a

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int a = 0, t = 0;
    rep(i, 0, n){
        if(s[i] == 'T') t++;
        else a++;
        if(t >= (n+1)/2){
            cout << 'T' << endl;
            return 0;
        }else if(a >= (n+1)/2){
            cout << 'A' << endl;
            return 0;
        }
    }

    return 0;
}