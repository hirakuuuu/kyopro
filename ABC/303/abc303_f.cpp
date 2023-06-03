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
// https://atcoder.jp/contests/abc303/tasks/abc303_f

int main(){
    ll n, h; cin >> n >> h;
    vector<ll> t(n+1), d(n+1);
    rep(i, 1, n+1) cin >> t[i] >> d[i];
    t.push_back(INF);
    
    // 時間の分割
    map<ll, ll> max_d;
    rep(i, 1, n+1) chmax(max_d[t[i]], d[i]);
    
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    vector<ll> dealt_damage_d(n+1), dealt_damage_td(n+1);
    rep(i, 1, n+1){
        chmax(dealt_damage_td[i], max(dealt_damage_td[i-1], t[i]*max_d[t[i]]));
        chmax(dealt_damage_d[n-i], max(dealt_damage_d[n-i+1], max_d[t[n-i]]));
    }

    ll ok = h, ng = 0;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        // midターンで与えられる最大ダメージを求める
        ll damage = 0;
        rep(i, 0, n+1){
            ll l = t[i], r = min(mid+1, t[i+1]);
            if(mid < l) continue;

            ll j = INF;
            if(dealt_damage_d[i] > 0) j = (dealt_damage_td[i]+dealt_damage_d[i]-1)/dealt_damage_d[i];
            if(j < l){
                damage += dealt_damage_d[i]*(r+l-1)*(r-l)/2;
            }else if(l <= j and j < r){
                damage += dealt_damage_td[i]*(r-l)+dealt_damage_d[i]*(j-l-1)*(j-l)/2;
            }else{
                damage += dealt_damage_td[i]*(r-l);
            }
        }
        if(damage >= h) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;


    


    
    return 0;
}