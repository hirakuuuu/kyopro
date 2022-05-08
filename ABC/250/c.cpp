#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc250/tasks/abc250_c

int main(){
    int n, q; cin >> n >> q;
    vector<int> a(n+1), b(n+1);
    rep(i, 1, n+1){
        a[i] = i;
        b[i] = i;
    }
    while(q--){
        int x; cin >> x;
        int pos = a[x];
        if(pos == n){
            int c = b[pos], d = b[pos-1];
            swap(b[pos], b[pos-1]);
            swap(a[c], a[d]);
        }else{
            int c = b[pos], d = b[pos+1];
            swap(b[pos], b[pos+1]);
            swap(a[c], a[d]);
        }
    }
    rep(i, 1, n+1){
        if(i > 1) cout << ' ';
        cout << b[i];
    }
    cout << endl;

    
    return 0;
}