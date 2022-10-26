#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bc

int main(){
    int q; cin >> q;
    set<int> s;
    while(q--){
        int t, x; cin >> t >> x;
        if(t == 1){
            s.insert(x);
        }else if(t == 2){
            s.erase(x);
        }else{
            auto itr = s.lower_bound(x);
            if(itr != s.end()) cout << *itr << "\n";
            else cout << -1 << "\n";
        }
    }
    
    return 0;
}