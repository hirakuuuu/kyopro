#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
https://atcoder.jp/contests/agc014/tasks/agc014_b
条件を満たすならば、木の形は関係ない → 直線に1~nを並べた木を考える
辺を通った回数をカウントする → 順番に並んでいるのでいもす法
*/

int main(){
    int n, m; cin >> n >> m;
    vector<int> cnt(n);
    while(m--){
        int a, b; cin >> a >> b;
        a--;
        b--;
        if(a > b) swap(a, b);
        cnt[a]++;
        cnt[b]--;
    }
    rep(i, 1, n){
        cnt[i] += cnt[i-1];
    }
    rep(i, 0, n){
        if(cnt[i]%2){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}