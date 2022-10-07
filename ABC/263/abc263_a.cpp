#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc263/tasks/abc263_a

int main()
{
    vector<int> cnt(14);
    rep(i, 0, 5){
        int card; cin >> card;
        cnt[card]++;
    }

    bool f2 = false, f3 = false;

    rep(i, 1, 14){
        if(cnt[i] == 2) f2 = true;
        if(cnt[i] == 3) f3 = true;
    } 

    if(f2 and f3) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}