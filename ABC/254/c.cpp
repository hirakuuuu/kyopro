#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc254/tasks/abc254_c

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n), b(k);
    map<int , map<int, int>> m;
    rep(i, 0, n){
        cin >> a[i];
        m[a[i]][i%k]++;
    }
    sort(a.begin(), a.end());
    rep(i, 0, n){
        if(m[a[i]][i%k]){
            m[a[i]][i%k]--;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;


    
    return 0;
}