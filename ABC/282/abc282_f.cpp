#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc282/tasks/abc282_f

int main(){
    int n; cin >> n;
    vector<pii> lr;
    int i = 0, id=  0;
    while(i <= n){
        int l = 1, r = l+i;
        while(l <= n){
            lr.push_back({l, min(n, r)});
            l += i;
            r += i;
            id++;
        }
    }
    cout << lr.size() << endl;
    rep(i, 0, lr.size()){
        cout << lr[i].first << ' ' << lr[i].second << endl;
    }

    int q; cin >> q;
    while(q--){
        int L, R; cin >> L >> R;
        
    }
    
    return 0;
}