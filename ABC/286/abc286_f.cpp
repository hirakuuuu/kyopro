#include <bits/stdc++.h>
#include <atcoder/math>
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
// https://atcoder.jp/contests/abc286/tasks/abc286_f

vector<ll> p = {4, 5, 7, 9, 11, 13, 17, 19, 23};

int main(){
    const ll m = 108;
    vector<ll> a(m);
    ll id = 0;
    for(const auto &pp: p){
        ll s = id+1;
        rep(i, 0, pp){
            a[id] = s+(pp-(s-id))%pp;
            id++;
        }
    }
    cout << m << endl;

    rep(i, 0, m){
        cout << a[i] << ' ';
    }
    cout << endl;

    vector<ll> r;
    vector<ll> b(m);
    rep(i, 0, m) cin >> b[i];
    id = 0;
    ll sm = 0;
    for(const auto &pp: p){
        sm += pp;
        r.push_back((1+(sm-b[id]))%pp);
        id += pp;
    }


    pll res = atcoder::crt(r, p);
    cout << res.first << endl;

    return 0;
}