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
// https://atcoder.jp/contests/abc299/tasks/abc299_d

int main(){
    int n; cin >> n;
    int l = 1, r = n;
    while(r-l > 1){
        int m = (l+r)/2;
        cout << "? "<< m << endl;
        int s; cin >> s;
        if(s == 0) l = m;
        else r = m;
    }
    cout << "! " << l << endl;
    
    return 0;
}