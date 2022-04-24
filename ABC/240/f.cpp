#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc240/tasks/abc240_f

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> pres;
    rep(i, 0, n){
        cin >> a[i];
        pres.push_back({a[i], 0, i});
    }
    rep(i, 0, n){
        cin >> b[i];
        pres.push_back({b[i], 1, i});
    }
    sort(pres.begin(), pres.end());
    reverse(pres.begin(), pres.end());
    vector<bool> fa(n), fb(n);

    multiset<int> oa, ob;
    rep(i, 0, n) oa.insert(a[i]);
    rep(i, 0, n) ob.insert(b[i]);

    ll ans = n;
    for(auto p: pres){
        if(!p[1]){
            ans += distance(ob.lower_bound(p[0]), ob.end())-1;
            ob.erase(p[0]);   
        }else{
            ans += distance(oa.lower_bound(p[0]), oa.end())-1;
            oa.erase(p[0]); 
        }
    }
    cout << ans << endl;
    return 0;
}