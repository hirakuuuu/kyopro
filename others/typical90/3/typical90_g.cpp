#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_g

/*
要素の検索　→　ソートして二分探索
・先に十分小さい値と十分大きい値を入れておくと、場合分けしなくて済む
*/

int main(){
    int n; cin >> n;
    vector<ll> a(n+2);
    rep(i, 0, n) cin >> a[i];
    a[n] = -(1LL<<50), a[n+1] = 1LL<<50;
    sort(a.begin(), a.end());

    int q; cin >> q;
    vector<ll> ans;
    while(q--){
        ll b; cin >> b;
        auto itr = lower_bound(a.begin(), a.end(), b);
        ll r = *itr;
        --itr;
        ll l = *itr;
        ans.push_back(min(r-b, b-l));
    }

    for(auto aa: ans){
        cout << aa << endl;
    }
    
    return 0;
}