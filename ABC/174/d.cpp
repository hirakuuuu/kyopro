#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc174/tasks/abc174_d

int main(){
    int n; cin >> n;
    string c; cin >> c;
    vector<int> r, w;
    rep(i, 0, n){
        if(c[i] == 'R') r.push_back(i);
        else w.push_back(i);
    }
    if(!r.size() or !w.size()){
        cout << 0 << endl;
        return 0;
    }

    int ir = 0, iw = 0, ans = 0;
    rep(i, 0, r.size()){
        if(r[i] < r.size()) continue;
        else{
            ir = i;
            break;
        }
    }
    while(ir < r.size() and iw < w.size()){
        if(r[ir] < w[iw]) ir++;
        else{
            swap(r[ir], w[iw]);
            ans++;
            ir++;
            iw++;
        }
    }
    cout << ans << endl; 
    return 0;
}