#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cw

int v[100005];

int main(){
    int n; cin >> n;
    vector<pii> box(n);
    rep(i, 0, n){
        int a, b; cin >> a >> b;
        box[i] = {a, -b};
    }
    sort(box.begin(), box.end());

    rep(i, 0, n+1) v[i] = 1e9;
    int len = 0;

    rep(i, 0, n){
        int pos = lower_bound(v, v+len, -box[i].second)-v;
        v[pos] = -box[i].second;
        if(len == pos) len++;
    }

    cout << len << endl;

    
    return 0;
}