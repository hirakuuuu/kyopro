#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    ll n, q, x; cin >> n >> q >> x;
    vector<ll> w(2*n), sw(2*n+1);
    ll sum = 0;
    rep(i, 0, n){
        cin >> w[i];
        sum += w[i];
        w[i+n] = w[i];
    }
    rep(i, 1, 2*n+1){
        sw[i] = sw[i-1]+w[i-1];
    }
    
    vector<ll> ans(n);
    rep(i, 0, n){
        int pos = lower_bound(sw.begin(), sw.end(), sw[i]+x%sum)-sw.begin();
        ans[i] = (x/sum)*n+pos-i;
    }

    vector<ll> seen(n);
    ll tmp = 0;
    vector<int> roop = {0};
    while(!seen[tmp]){
        seen[tmp] = true;
        tmp += ans[tmp];
        tmp %= n;
        if(!seen[tmp]) roop.push_back(tmp);
    }

    ll l = 0;
    while(roop[l] != tmp) l++;
    ll r = roop.size()-l;


    while(q--){
        ll k; cin >> k;
        k--;
        if(k <= l){
            cout << ans[roop[k]] << endl;
        }else{
            cout << ans[roop[l+(k-l)%r]] << endl;

        }

    }
    
    return 0;
}