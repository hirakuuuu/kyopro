#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc247/tasks/abc247_d

int main(){
    int q; cin >> q;
    deque<pll> que;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            ll x, c; cin >> x >> c;
            que.push_back({x, c});
        }else{
            ll c; cin >> c;
            ll res = 0;
            while(c){
                pll p = que.front(); que.pop_front();
                if(c >= p.second){
                    res += p.first*p.second;
                    c -= p.second;
                }else{
                    res += p.first*c;
                    que.push_front({p.first, p.second-c});
                    c = 0;
                }
            }
            cout << res << endl;
        }
    }
    
    return 0;
}