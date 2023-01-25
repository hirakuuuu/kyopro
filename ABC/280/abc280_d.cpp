#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc280/tasks/abc280_d

int main(){
    ll k; cin >> k;
    ll k_ = k;
    map<ll, ll> m;
    for(ll i = 2; i*i <= k; i++){
        if(k_%i == 0){
            while(k_%i == 0){
                k_ /= i;
                m[i]++;
            }
        }
    }
    if(k_ != 1) m[k_]++;

    ll ng = 1, ok = 1LL<<60;
    while(ok-ng > 1){
        ll mid = (ng+ok)/2;
        bool f = true;
        for(const auto &mm: m){
            ll p = mm.first, cnt = mm.second;
            ll q = p, tmp = 0;
            while(cnt >= tmp and mid >= q){
                tmp += mid/q;
                if(mid/q < p) break;
                q *= p;
            }
            if(cnt > tmp) f = false;
        }
        if(f) ok = mid;
        else ng = mid;

    }

    cout << ok << endl;
    
    return 0;
}