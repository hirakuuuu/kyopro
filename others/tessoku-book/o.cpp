#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_o

int n, a[100005], ans[100005];
vector<int> b;

int main(){
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) b.push_back(a[i]);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    rep(i, 0, n){
        int pos = lower_bound(b.begin(), b.end(), a[i])-b.begin();
        if(i > 0) cout << ' ';
        cout << pos+1;
    }
    cout << endl;

    return 0;
}