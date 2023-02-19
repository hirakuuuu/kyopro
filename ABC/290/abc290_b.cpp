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
// https://atcoder.jp/contests/abc290/tasks/abc290_b

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> c;
    rep(i, 0, n){
        if(k and s[i] == 'o'){
            c.push_back(i);
            k--;
        }
    }

    string t;
    int pos = 0;
    rep(i, 0, n){
        if(c[pos] == i){
            pos++;
            t += 'o';
        }else{
            t += 'x';
        }
    }
    cout << t << endl;
    
    return 0;
}