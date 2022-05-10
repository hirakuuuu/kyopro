#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_j

/*
区間の和は累積和で求める
・配列aの累積和を取ったbという配列を考えると
・区間[l, r]の和はb[r]-b[l-1]で求められる
・インデックスを1から始めること必要
*/

int main(){
    int n; cin >> n;
    vector<int> c1(n+1), c2(n+1);
    rep(i, 1, n+1){
        int c, p; cin >> c >> p;
        if(c == 1) c1[i] += p;
        else c2[i] += p;
        c1[i] += c1[i-1];
        c2[i] += c2[i-1];
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        printf("%d %d\n", c1[r]-c1[l-1], c2[r]-c2[l-1]);
    }
    
    return 0;
}