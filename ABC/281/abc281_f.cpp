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
// https://atcoder.jp/contests/abc281/tasks/abc281_f

vector<int> a;
int f(int l, int r, int p, int o){
    if(o < 0) return 0;
    else if(r-l == 1) return 0;

    int m = lower_bound(a.begin()+l, a.begin()+r, p+(1<<o))-a.begin();
    int res = 0;
    if(m == r) res = f(l, r, p, o-1);
    else if(m == l) res = f(l, r, p+(1<<o), o-1);
    else{
        res = (1<<o)+min(f(l, m, p, o-1), f(m, r, p+(1<<o), o-1));
    }
    return res;
}

int main(){
    int n; cin >> n;
    a.resize(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    cout << f(0, n, 0, 29) << endl;




    
    return 0;
}