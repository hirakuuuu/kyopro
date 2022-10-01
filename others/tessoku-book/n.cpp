#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_n

int n, k;
int a[1005], b[1005], c[1005], d[1005];

int main(){
    cin >> n >> k;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, n) cin >> d[i];

    set<int> sum_cd;
    rep(i, 0, n){
        rep(j, 0, n) sum_cd.insert(c[i]+d[j]);
    }

    rep(i, 0, n){
        rep(j, 0, n){
            int need = *sum_cd.lower_bound(k-a[i]-b[j]);
            if(need == k-a[i]-b[j]){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    
    cout << "No" << endl;
    
    return 0;
}