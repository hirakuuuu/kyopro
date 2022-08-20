#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc146/tasks/arc146_a

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<pii> b(n);
    rep(i, 0, n){
        int o = 0, a_ = a[i];
        while(a_){
            a_ /= 10;
            o++;
        }
        b[i] = {o, a[i]};
    }

    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    vector<pii> c(3);
    int max_o = 0;

    rep(i, 0, 3){
        c[i] = {b[i].second, i};
        max_o = max(max_o, b[i].first);
    }

    rep(i, 0, 3){
        rep(_, 0, max_o-b[i].first){
            c[i].first *= 10;
        }
    }
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());

    rep(i, 0, 3){
        cout << b[c[i].second].second;
    }
    cout << endl;


    
    return 0;
}