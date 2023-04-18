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
// https://atcoder.jp/contests/abc298/tasks/abc298_c

int main(){
    int n, q; cin >> n >> q;

    vector<set<int>> bid(200005);
    vector<multiset<int>> cid(n+1);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int i, j; cin >> i >> j;
            bid[i].insert(j);
            cid[j].insert(i);
        }else if(t == 2){
            int i; cin >> i;
            for(auto itr = cid[i].begin(); itr != cid[i].end(); ++itr){
                cout << *itr << ' ';
            }
            cout << '\n';
        }else{
            int i; cin >> i;
            for(auto itr = bid[i].begin(); itr != bid[i].end(); ++itr){
                cout << *itr << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}