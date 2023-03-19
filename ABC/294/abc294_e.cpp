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
// https://atcoder.jp/contests/abc294/tasks/abc294_e

int main(){
    ll l; cin >> l;
    ll n1, n2; cin >> n1 >> n2;
    vector<pll> v1(n1+1), v2(n2+1);
    rep(i, 1, n1+1){
        ll vv, l1; cin >> vv >> l1;
        v1[i] = {vv, v1[i-1].second+l1};
    }
    rep(i, 1, n2+1){
        ll vv, l2; cin >> vv >> l2;
        v2[i] = {vv, v2[i-1].second+l2};
    }

    ll ans = 0;

    ll pos1 = 1, pos2 = 1;
    ll L = 0;
    while(pos1 <= n1 and pos2 <= n2){
        if(v1[pos1].second < v2[pos2].second){
            if(v1[pos1].first == v2[pos2].first){
                ans += v1[pos1].second - L;
            }
            L = v1[pos1].second;
            pos1++;
        }else{
            if(v1[pos1].first == v2[pos2].first){
                ans += v2[pos2].second - L;
            }
            L = v2[pos2].second;
            pos2++;
        }
    }
    cout << ans << endl;

    return 0;
}