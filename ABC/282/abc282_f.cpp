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
// https://atcoder.jp/contests/abc282/tasks/abc282_f

int main(){
    int n; cin >> n;
    vector<pii> lr;
    vector<vector<int>> l_id(30, vector<int>(n+1));
    vector<vector<int>> r_id(30, vector<int>(n+1));
    int wid = 1, id = 0, m = 0;
    while(wid <= n){
        int i = 1;
        while(i+wid-1 <= n){
            lr.push_back({i, i+wid-1});
            m++;
            l_id[id][i] = m;
            r_id[id][i+wid-1] = m;
            i++;
        }
        id++;
        wid *= 2;
    }
    cout << lr.size() << endl;
    for(const auto &p: lr){
        cout << p.first << ' ' << p.second << endl;
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        int o = 0;
        while(pow(2, o) <= r-l+1){
            o++;
        }
        o--;
        cout << l_id[o][l] << ' ' << r_id[o][r] << endl;

    }

    
    return 0;
}