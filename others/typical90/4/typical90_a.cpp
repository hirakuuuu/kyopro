#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_a

/*
最小値の最大値を求める　→　二分探索
・l = -1, r = L+1とする
・m = (l+r)/2 とし、全てのピースの長さが m 以上になるように分割
・k+1個以上のピースに分割できる　→　l = m
・k個以下にしか分割できない　→　r = m
*/

int a[100005];

int main(){
    int n, L; cin >> n >> L;
    int k; cin >> k;
    rep(i, 0, n) cin >> a[i];
    a[n] = L;
    sort(a, a+n+1);

    int l = 0, r = L;
    while(r-l > 1){
        int m = (l+r)/2;
        int s = 0, cnt = 0;
        rep(i, 0, n+1){
            if(a[i]-s >= m){
                s = a[i];
                cnt++;
            }
        }
        if(cnt >= k+1) l = m;
        else r = m;
    }
    cout << l << endl;
    
    return 0;
}