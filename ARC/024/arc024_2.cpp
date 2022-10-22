#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc024/tasks/arc024_2

int main(){
    int n; cin >> n;
    vector<int> c(n);
    rep(i, 0, n) cin >> c[i];
    vector<int> red, black;
    rep(i, 0, 2*n){
        if(c[i%n] == 0) black.push_back(i);
        else red.push_back(i);
    }

    int ans = -1;
    if(red.size() < 2*n and black.size() < 2*n){
        rep(i, 0, n){
            int len;
            if(c[i] == 0){
                len = *upper_bound(red.begin(), red.end(), i)-i;
            }else{
                len = *upper_bound(black.begin(), black.end(), i)-i;
            }
            ans = max(ans, len);
        }
    }

    if(ans == -1) cout << -1 << endl;
    else cout << (ans-1)/2+1 << endl;
    
    return 0;
}