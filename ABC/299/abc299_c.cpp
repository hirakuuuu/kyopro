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
// https://atcoder.jp/contests/abc299/tasks/abc299_c

int main(){
    int n; cin >> n;
    string s; cin >> s;
    bool f1 = false, f2 = false;
    rep(i, 0, n){
        if(s[i] == '-') f1 = true;
        else f2 = true;
    }

    int ans = -1;
    if(f1 and f2){
        rep(i, 0, n){
            int j = i;
            while(j < n and s[j] == 'o'){
                j++;
            }

            chmax(ans, j-i);
            i = j;
        }
    }
    cout << ans << endl;
    
    return 0;
}