#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc138/tasks/arc138_a

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(k), b(n-k);
    rep(i, 0, k){
        cin >> a[i];
    }
    rep(i, 0, n-k){
        cin >> b[i];
    }
    set<int> s;
    map<int, int> m;
    int c = MOD;
    rep(i, 0, k){
        if(c > a[k-i-1]){
            s.insert(a[k-i-1]);
            m[a[k-i-1]] = k-i-1;
            c = a[k-i-1];
        }
    }

    int ans = -1;
    rep(i, 0, n-k){
        auto itr = s.lower_bound(b[i]);
        if(itr == s.begin()) continue;
        --itr;
        if(ans < 0) ans = i+k-m[*itr];
        else ans = min(ans, i+k-m[*itr]);
    }
    cout << ans << endl;

    
    return 0;
}