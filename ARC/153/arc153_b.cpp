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
// https://atcoder.jp/contests/arc153/tasks/arc153_b



int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    int pos_h = 0, pos_w = 0;
    int q; cin >> q;
    int f = q%2;
    while(q--){
        int a, b; cin >> a >> b;
        a--, b--;
        // 行について
        if(pos_h <= a) pos_h = a-pos_h;
        else pos_h = h-pos_h+a;
        // 列について
        if(pos_w <= b) pos_w = b-pos_w;
        else pos_w = w-pos_w+b;
    }

    vector<int> ans_h(h), ans_w(w);
    if(f == 0){
        rep(i, 0, h) ans_h[(i+pos_h)%h] = i;
        rep(i, 0, w) ans_w[(i+pos_w)%w] = i;
    }else{
        rep(i, 0, h) ans_h[(h-i+pos_h)%h] = i;
        rep(i, 0, w) ans_w[(w-i+pos_w)%w] = i;
    }
    rep(i, 0, h){
        rep(j, 0, w){
            cout << s[ans_h[i]][ans_w[j]];
        }
        cout << endl;
    }
    return 0;
}