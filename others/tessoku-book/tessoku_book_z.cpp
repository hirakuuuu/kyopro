#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_z

int main(){
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        bool f = true;
        for(int i = 2; i*i <= x; i++){
            f &= (x%i != 0);
        }

        if(f) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}