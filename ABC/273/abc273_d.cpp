#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc273/tasks/abc273_d

int main(){
    ll h, w; cin >> h >> w;
    ll rs, cs; cin >> rs >> cs;

    ll n; cin >> n;
    vector<ll> r(n), c(n);
    map<ll, vector<ll>> wall_r, wall_c;
    map<ll, vector<ll>> wall_rm, wall_cm;
    
    rep(i, 0, n){
        cin >> r[i] >> c[i];
        wall_r[r[i]].push_back(c[i]);
        wall_rm[r[i]].push_back(-c[i]);
        wall_c[c[i]].push_back(r[i]);
        wall_cm[c[i]].push_back(-r[i]);
    }

    for(auto &wr: wall_r){
        sort(wr.second.begin(), wr.second.end());
    }
    for(auto &wrm: wall_rm){
        sort(wrm.second.begin(), wrm.second.end());
    }
    for(auto &wc: wall_c){
        sort(wc.second.begin(), wc.second.end());
    }
    for(auto &wcm: wall_cm){
        sort(wcm.second.begin(), wcm.second.end());
    }

    ll q; cin >> q;
    vector<pll> ans;
    while(q--){
        char d; cin >> d;
        ll l; cin >> l;

        if(d == 'L'){
            auto itr = lower_bound(wall_rm[rs].begin(), wall_rm[rs].end(), -cs+1);
            if(itr == wall_rm[rs].end()) cs = max(cs-l, 1LL);
            else cs = max(cs-l, -(*itr)+1);
        }else if(d == 'R'){
            auto itr = lower_bound(wall_r[rs].begin(), wall_r[rs].end(), cs+1);
            if(itr == wall_r[rs].end()) cs = min(cs+l, w);
            else cs = min(cs+l, (*itr)-1);
        }else if(d == 'U'){
            auto itr = lower_bound(wall_cm[cs].begin(), wall_cm[cs].end(), -rs+1);
            if(itr == wall_cm[cs].end()) rs = max(rs-l, 1LL);
            else rs = max(rs-l, -(*itr)+1);
        }else{
            auto itr = lower_bound(wall_c[cs].begin(), wall_c[cs].end(), rs+1);
            if(itr == wall_c[cs].end()) rs = min(rs+l, h);
            else rs = min(rs+l, (*itr)-1);
        }
        ans.push_back({rs, cs});
    }
    for(auto aa: ans){
        printf("%lld %lld\n", aa.first, aa.second);
    }
    
    return 0;
}