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
// https://atcoder.jp/contests/abc281/tasks/abc281_e

int main(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    multiset<ll> mins, maxs;
    vector<ll> b(m);
    rep(i, 0, m) b[i] = a[i];
    sort(b.begin(), b.end());
    vector<ll> ans(n-m+1);
    rep(i, 0, m){
        if(i < k){
            mins.insert(b[i]);
            ans[0] += b[i];
        }else{
            maxs.insert(b[i]);
        }
    }

    rep(i, 1, n-m+1){
        ans[i] = ans[i-1];
        if(!maxs.empty() && *maxs.begin() <= a[i-1]){
            maxs.erase(a[i-1]);
            ll c = *prev(mins.end());
            if(a[i+m-1] < c){
                mins.erase(prev(mins.end()));
                ans[i] -= c;
                mins.insert(a[i+m-1]);
                ans[i] += a[i+m-1];
                maxs.insert(c);
            }else{
                maxs.insert(a[i+m-1]);
            }
        }else{
            mins.erase(a[i-1]);
            ans[i] -= a[i-1];
            if(maxs.empty() || a[i+m-1] <= *maxs.begin()){
                mins.insert(a[i+m-1]);
                ans[i] += a[i+m-1];
            }else{
                ll c = *maxs.begin();
                mins.insert(c);
                ans[i] += c;
                maxs.erase(maxs.begin());
                maxs.insert(a[i+m-1]);
            }
        }
    }

    rep(i, 0, n-m+1) cout << ans[i] << ' ';
    cout << endl;

    
    return 0;
}