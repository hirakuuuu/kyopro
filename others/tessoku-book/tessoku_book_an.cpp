#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_an

int main(){
    int n; cin >> n;
    vector<ll> cnt(101);
    rep(i, 0, n){
        ll a; cin >> a;
        cnt[a]++;
    }

    ll ans = 0;
    rep(i, 1, 101){
        ans += (cnt[i]-2)*(cnt[i]-1)*cnt[i]/6;
    }

    cout << ans << endl;
    
    return 0;
}