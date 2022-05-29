#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc253/tasks/abc253_c

int main(){
    int q; cin >> q;
    set<int> s;
    map<int, int> cnt;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            s.insert(x);
            cnt[x]++;
        }else if(t == 2){
            int x, c; cin >> x >> c;
            cnt[x] = max(cnt[x]-c, 0);
            if(cnt[x] == 0) s.erase(x);
        }else{
            int l = *s.begin(), r = *s.rbegin();
            cout << r-l << endl;
        }
    }
    
    return 0;
}