#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc257/tasks/abc257_e

int main(){
    int n; cin >> n;
    vector<int> c(10);
    rep(i, 1, 10) cin >> c[i];
    
    ll max_n = 0, max_i = 0;
    rep(i, 1, 10){
        if(max_n <= n/c[i]){
            max_n = n/c[i];
            max_i = i;
        }
    }

    ll rest = n-(c[max_i]*max_n);
    string ans_start = "";



    for(int i = 9; i >= max_i+1; i--){
        ll cnt = 0;
        while(rest+c[max_i] >= c[i]){
            rest += c[max_i]-c[i];
            cnt++;
        }
        if(cnt){
            rep(j, 0, cnt) ans_start += '0'+i;
        }
    }
    cout << ans_start;

    rep(i, 0, max_n-ans_start.size()){
        cout << max_i;
    }
    cout << endl;

    
    return 0;
}