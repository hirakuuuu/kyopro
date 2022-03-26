#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc245/tasks/abc245_e

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, m) cin >> c[i];
    rep(i, 0, m) cin >> d[i];
    
    vector<vector<int>> abcd;
    rep(i, 0, n) abcd.push_back({a[i], b[i], 0});
    rep(i, 0, m) abcd.push_back({c[i], d[i], 1});
    sort(abcd.begin(), abcd.end());
    reverse(abcd.begin(), abcd.end());

    multiset<int> s;
    for(auto e: abcd){
        if(e[2] == 0){
            auto itr = s.lower_bound(e[1]);
            if(itr == s.end()){
                cout << "No" << endl;
                return 0;
            }
            s.erase(itr);
        }else{
            s.insert(e[1]);
        }
    }
    cout << "Yes" << endl;
    return 0;
}