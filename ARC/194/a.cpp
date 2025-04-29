#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    set<pair<ll, ll>> s;
    set<pair<ll, ll>> t;
    ll ans = 0;
    rep(i, 0, n){
        ans += a[i];
        s.insert({i, a[i]});
        t.insert({a[i], i});
    }

    for(auto [val, key]: t){
        if(!s.count({key, val})) continue;
        
        auto itr = s.find({key, val});
        cout << (*itr).first << ' ' << (*itr).second << endl;

        ll tmp_l = INF, tmp_r = INF;
        if(itr != s.begin()){
            auto itr_l = prev(itr);
            tmp_l = (*itr).second+(*itr_l).second;
            // ans -= (*itr).second+(*itr_l).second;
            // s.erase(itr);
            // itr--;
            // s.erase(itr);
        }
        if(next(itr) != s.end()){
            auto itr_r = itr;
            itr_r++;
            tmp_r = (*itr).second+(*itr_r).second;
        }

        if(tmp_l >= 0 && tmp_r >= 0) continue;
        // cout << "##" <<  tmp_l << ' ' << tmp_r << endl;
        if(tmp_l < tmp_r){
            auto itr_l = prev(itr);
            ans -= (*itr).second+(*itr_l).second;
            s.erase(itr);
            s.erase(itr_l);
    
        }else{
            auto itr_r = itr;
            itr_r++;
            ans -= (*itr).second+(*itr_r).second;
            s.erase(itr);
            s.erase(itr_r);
        }
    }
    cout << ans << endl;
    return 0;
}