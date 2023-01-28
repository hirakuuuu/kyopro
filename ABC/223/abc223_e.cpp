#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc223/tasks/abc223_e

int main(){
    ll x, y; cin >> x >> y;
    vector<ll> ar(3);
    rep(i, 0, 3) cin >> ar[i];
    ll a = 0, b = 0, c = 0;


    ll h = 0, w = 0;
    bool f = false;

    a = ar[0], b = ar[1], c = ar[2];
    // 縦にA, Bを並べる
    h = y, w = x-((a+y-1)/y)-((b+y-1)/y);
    if(c <= h*w) f = true;
    // 横にA, Bを並べる
    h = y-((a+x-1)/x)-((b+x-1)/x), w = x;
    if(c <= h*w) f = true;
    rep(i, 0, 3){
        a = ar[i], b = ar[(i+1)%3], c = ar[(i+2)%3];
        // 縦にA、横にBを並べる
        w = x-((a+y-1)/y);
        if(w > 0){
            h = y-((b+w-1)/w);
            if(c <= h*w) f = true;
        }
        // 縦にB、横にAを並べる
        w = x-((b+y-1)/y);
        if(w > 0){
            h = y-((a+w-1)/w);
            if(c <= h*w) f = true;
        }
        // 横にA、縦にBを並べる
        h = y-((a+x-1)/x);
        if(h > 0){
            w = x-((b+h-1)/h);
            if(c <= h*w) f = true;
        }
        // 横にB、縦にAを並べる
        h = y-((b+x-1)/x);
        if(h > 0){
            w = x-((a+h-1)/h);
            if(c <= h*w) f = true;
        }
    }


    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;


    
    return 0;
}