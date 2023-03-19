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
// https://atcoder.jp/contests/abc294/tasks/abc294_d

int main(){
    int n, q; cin >> n >> q;
    set<int> wait, called;
    rep(i, 1, n+1) wait.insert(i);

    int wait_min = 1;

    while(q--){
        int t; cin >> t;
        if(t == 1){
            wait.erase(wait_min);
            called.insert(wait_min);
            wait_min++;
        }else if(t == 2){
            int x; cin >> x;
            called.erase(x);
        }else{
            cout << *called.begin() << endl;
        }
    }

    
    return 0;
}