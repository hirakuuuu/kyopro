#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc298/tasks/abc298_d

int main(){
    int q; cin >> q;
    vector<ll> m(q+1);
    m[0] = 1;
    rep(i, 1, q+1){
        m[i] = (m[i-1]*10)%mod_num;
    }
    ll tmp = 1;
    vector<int> s;
    s.push_back(1);
    int sid = 0;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            tmp = (10*tmp+x)%mod_num;
            s.push_back(x);
        }else if(t == 2){
            tmp -= s[sid]*m[s.size()-sid-1]%mod_num;
            if(tmp < 0) tmp += mod_num;
            sid++;
        }else{
            cout << tmp << endl;
        }
    }
    return 0;
}