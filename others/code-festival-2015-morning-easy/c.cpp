#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/code-festival-2015-morning-easy/tasks/cf_2015_morning_easy_c

int main(){
    int n, k, m, r; cin >> n >> k >> m >> r;
    vector<int> s(n-1);
    rep(i, 0, n-1) cin >> s[i];
    sort(s.begin(), s.end(), greater<int>());

    if(n != k){
        double s = 0;
        rep(i, 0, k-1){

        }


    }
    
    return 0;
}