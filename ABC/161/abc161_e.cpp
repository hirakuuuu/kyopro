#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc161/tasks/abc161_e

int main(){
    int n, k, c; cin >> n >> k >> c;
    string s; cin >> s;

    vector<int> l(k), r(k);
    int cnt_k = 0;
    int pos = 0;
    int k_ = k;
    while(k_){
        if(s[pos] == 'o'){
            k_--;
            l[cnt_k] = pos;
            pos += c;
            cnt_k++;
        }
        pos++;
    }

    cnt_k = k-1;
    pos = n-1;
    k_ = k;
    while(k_){
        if(s[pos] == 'o'){
            k_--;
            r[cnt_k] = pos;
            pos -= c;
            cnt_k--;
        }
        pos--;
    }

    rep(i, 0, k){
        if(l[i] == r[i]) cout << l[i]+1 << "\n";
    }



    return 0;
}