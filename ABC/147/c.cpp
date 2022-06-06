#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc147/tasks/abc147_c

int main(){
    int n; cin >> n;
    vector<vector<pii>> a(n);
    rep(i, 0, n){
        int b; cin >> b;
        rep(j, 0, b){
            int x, y; cin >> x >> y;
            x--;
            a[i].push_back({x, y});
        }
    }

    int ans = 0;

    rep(i, 0, 1<<n){
        vector<int> bit(n);
        int dir = i, cnt = 0;
        rep(j, 0, n){
            bit[j] = dir%2;
            cnt += bit[j];
            dir /= 2;
        }

        bool flag = true;
        rep(j, 0, n){
            if(bit[j] == 1){
                for(auto aa: a[j]){
                    if(bit[aa.first] != aa.second){
                        flag = false;
                        break;
                    }
                }
            }
        }

        if(flag) ans = max(ans, cnt);
    }

    cout << ans << endl;
    
    return 0;
}