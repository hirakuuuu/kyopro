#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
// 問題
// https://atcoder.jp/contests/tenka1-2017/tasks/tenka1_2017_d

vector<ll> a(100005), b(100005);
vector<int> bit(35, -1);

ll get_sum(ll n){
    ll res = 0;
    rep(i, 0, n){
        bool f = true;
        rep(j, 0, 31){
            if(bit[j] == -1) continue;
            if((a[i]&(1<<j)) > 0 and bit[j] == 0) f = false;
        }
        if(f) res += b[i];
    }
    return res;
}

ll f(ll n, ll k, int i){
    if(i == -1) return get_sum(n);
    ll sum_1 = 0, sum_2 = 0;
    if((k&(1<<i)) > 0){
        bit[i] = 0;
        sum_1 = get_sum(n);
        bit[i] = 1;
        sum_2 = f(n, k, i-1);
    }else{
        bit[i] = 0;
        sum_1 = f(n, k, i-1);
    }
    return max(sum_1, sum_2);
}


int main(){
    ll n, k; cin >> n >> k;
    rep(i, 0, n) cin >> a[i] >> b[i];
    cout << f(n, k, 30) << endl;

    return 0;
}