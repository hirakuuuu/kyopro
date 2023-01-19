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
// https://atcoder.jp/contests/arc153/tasks/arc153_c

int main(){
    ll n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> x(n);
    iota(x.begin(), x.end(), 0);
    ll total = 0, gap = 0;
    rep(i, 0, n){
        total += x[i]*a[i];
        gap += a[i];
    }
    if(total == 0){
        cout << "Yes" << endl;
        rep(i, 0, n) cout << x[i] << ' ';
        cout << endl;
    }else if((total != 0 and gap == 0) or (total*gap > 0)){
        cout << "No" << endl;
    }else{
        ll b = total*gap;
    }
    

    
    return 0;
}