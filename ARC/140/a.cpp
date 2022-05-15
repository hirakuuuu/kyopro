#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc140/tasks/arc140_a

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> yakusu;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            yakusu.push_back(i);
            if(i != n/i) yakusu.push_back(n/i);
        }
    }

    sort(yakusu.begin(), yakusu.end());

    for(auto y: yakusu){
        vector<vector<int>> cnt(y, vector<int>(26));
        rep(i, 0, n) cnt[(i+1)%y][s[i]-'a']++;
        int need = 0;
        rep(i, 0, y){
            int max_cnt = 0;
            rep(j, 0, 26) max_cnt = max(max_cnt, cnt[i][j]);
            need += n/y-max_cnt;
        }
        if(need <= k){
            cout << y << endl;
            return 0;
        }
    }
    return 0;
}