#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc224/tasks/abc224_e



int main(){
    int h, w, n; cin >> h >> w >> n;
    vector<int> r(n), c(n);
    vector<pii> a(n);
    rep(i, 0, n){
        cin >> r[i] >> c[i] >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<int> ans(n), rs(h+1), cs(w+1);

    rep(i, 0, n){
        int max_a = a[i].first;
        map<int, int> mr, mc;
        while(i < n and a[i].first == max_a){
            int id = a[i].second;
            ans[id] = max(rs[r[id]], cs[c[id]]);
            mr[r[id]] = max(mr[r[id]], ans[id]+1);
            mc[c[id]] = max(mc[c[id]], ans[id]+1);
            i++;
        }
        i--;
        for(auto itr = mr.begin(); itr != mr.end(); ++itr){
            rs[itr->first] = max(rs[itr->first], itr->second);
        }
        for(auto itr = mc.begin(); itr != mc.end(); ++itr){
            cs[itr->first] = max(cs[itr->first], itr->second);
        }
    }
    rep(i, 0, n) cout << ans[i] << endl;

    return 0;
}