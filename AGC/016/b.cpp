#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc016/tasks/agc016_b

int main(){
    int n; cin >> n;
    vector<int> a(n);
    int max_a = 0, min_a = 100005;
    rep(i, 0, n){
        cin >> a[i];
        max_a = max(max_a, a[i]);
        min_a = min(min_a, a[i]);
    }

    bool f = false;
    if(max_a-min_a == 1){
        int cnt_M = 0, cnt_m = 0;
        rep(i, 0, n){
            if(a[i] == min_a) cnt_m++;
            else cnt_M++;
        }
        int need = min_a+1-cnt_m;
        if(need > 0 and cnt_M/need >= 2) f=true;
    }else if(max_a-min_a == 0){
        if(n/max_a >= 2) f = true;
        if(min_a == n-1) f = true;

    }

    if(f)cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}