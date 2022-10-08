#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc272/tasks/abc272_c

int main(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];
    vector<int> e, o;
    rep(i, 1, n+1){
        if(a[i]%2 == 0) e.push_back(a[i]);
        else o.push_back(a[i]);
    }

    if(e.size() > 0) sort(e.begin(), e.end());
    if(o.size() > 0) sort(o.begin(), o.end());

    if(e.size() < 2 and o.size() < 2){
        cout << -1 << endl;
    }else if(e.size() < 2){
        cout << o[o.size()-1]+o[o.size()-2] << endl;
    }else if(o.size() < 2){
        cout << e[e.size()-1]+e[e.size()-2] << endl;
    }else{
        cout << max(o[o.size()-1]+o[o.size()-2], e[e.size()-1]+e[e.size()-2]) << endl;
    }
    
    return 0;
}