#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc249/tasks/abc249_c

int main(){
    int n, k; cin >> n >> k;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    int ans = 0;
    rep(i, 0, 1<<n){
        vector<int> b(n);
        int ci = i;
        rep(j, 0, n){
            b[j] = ci%2;
            ci /= 2;
        }
        vector<int> num(26);
        rep(j, 0, n){
            if(b[j]){
                for(auto ss: s[j]) num[ss-'a']++;
            }
        }
        int cnt = 0;
        rep(j, 0, 26){
            if(num[j] == k) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    
    return 0;
}