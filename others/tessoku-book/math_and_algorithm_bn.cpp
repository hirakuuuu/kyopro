#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_bn

int main(){
    int n; cin >> n;
    vector<int> l(n), r(n);
    rep(i, 0, n) cin >> l[i] >> r[i];

    vector<pii> eiga(n);
    rep(i, 0, n) eiga[i] = {r[i], l[i]};
    sort(eiga.begin(), eiga.end());

    int s = 0, cnt = 0;
    rep(i, 0, n){
        if(s <= eiga[i].second){
            s = eiga[i].first;
            cnt++;
        }
    }

    cout << cnt << endl;


    return 0;
}