#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc007/tasks/arc007_3

int main(){
    string c; cin >> c;
    int n = c.size();
    vector<vector<int>> rshift(n, vector<int>(n));

    rep(i, 0, n){
        rep(j, 0, n){
            if(c[j] == 'o'){
                rshift[i][(i+j)%n] = 1;
            }
        }
    }

    int ans = 10000;

    rep(i, 0, (1<<n)){
        vector<int> bit(n);
        int div = i;
        int cnt_1 = 0;
        rep(j, 0, n){
            bit[j] = div%2;
            cnt_1 += bit[j];
            div /= 2;
        }

        int cnt = 0;
        vector<int> can_watch(n);

        rep(j, 0, n){
            if(bit[j]){
                rep(k, 0, n){
                    if(rshift[j][k] and can_watch[k] == 0) can_watch[k] = 1;
                }
            }
        }

        rep(j, 0, n) cnt += can_watch[j];

        if(cnt == n){
            ans = min(ans, cnt_1);
        }
    }


    cout << ans << endl;
    
    return 0;
}