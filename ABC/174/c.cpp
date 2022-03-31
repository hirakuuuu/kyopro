#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc174/tasks/abc174_c

int main(){
    int k; cin >> k;
    vector<int> m(k);
    int a = 7%k, cnt = 1;
    m[a] = 1;
    while(true){
        if(a%k == 0){
            cout << cnt << endl;
            return 0;
        }
        a = (a*10+7)%k;
        if(m[a]) break;
        m[a] = 1;
        cnt++;
    }
    cout << -1 << endl;

    
    return 0;
}