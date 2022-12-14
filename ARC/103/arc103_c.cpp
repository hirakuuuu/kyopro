#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc103/tasks/arc103_c

int main(){
    string s; cin >> s;
    int n = s.size();
    bool f = (s[0] == '1') and (s[n-1] == '0');
    rep(i, 0, n/2){
        f &= (s[i] == s[n-i-2]);
    }

    if(f){
        s[n-1] = 1;
        int u = n, v = n-1;
        while(v >= 1){
            cout << v << ' ' << u << endl;
            if(s[v-1] == '1') u = v;
            v--;
        }
    }else{
        cout << -1 << endl;
    }

    
    return 0;
}