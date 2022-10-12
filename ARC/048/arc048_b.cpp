#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc048/tasks/arc048_b

int main(){
    int n; cin >> n;
    vector<int> r(n+1), h(n+1);
    rep(i, 1, n+1){
        cin >> r[i] >> h[i];
        h[i]--;
    }

    vector<vector<int>> cnt(100005, vector<int>(3));
    rep(i, 1, n+1){
        cnt[r[i]][h[i]]++;
    }

    vector<int> r_sorted = r;
    sort(r_sorted.begin(), r_sorted.end());

    rep(i, 1, n+1){
        int win = 0, lose = 0, draw = 0;
        // レートでの勝敗
        win += lower_bound(r_sorted.begin(), r_sorted.end(), r[i])-r_sorted.begin()-1;
        lose += r_sorted.end()-lower_bound(r_sorted.begin(), r_sorted.end(), r[i]+1);
        // じゃんけんでの勝敗
        win += cnt[r[i]][(h[i]+1)%3];
        lose += cnt[r[i]][(h[i]+2)%3];
        draw += cnt[r[i]][h[i]]-1;
        
        printf("%d %d %d\n", win, lose, draw);
    }
    
    return 0;
}