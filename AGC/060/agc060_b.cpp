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
// https://atcoder.jp/contests/agc060/tasks/agc060_b

int main(){
    int t; cin >> t;

    while(t--){
        int n, m, k; cin >> n >> m >> k;
        string s; cin >> s;

        int cnt = 0;
        rep(i, 0, s.size()-1){
            if(s[i] != s[i+1]){
                cnt++;
                i++;
            }
        }

        cout << (cnt <= k ? "Yes" : "No") << endl;
    }

    
    return 0;
}