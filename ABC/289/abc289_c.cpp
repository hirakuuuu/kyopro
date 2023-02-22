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
// https://atcoder.jp/contests/abc289/tasks/abc289_c

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> s(m);
    rep(i, 0, m){
        int c; cin >> c;
        rep(j, 0, c){
            int a; cin >> a;
            s[i].push_back(a);
        }
    }

    int ans = 0;

    rep(i, 1, (1<<m)){
        vector<int> exist(n+1);
        rep(j, 0, m){
            if((i&(1<<j)) > 0){
                for(const auto &aa: s[j]){
                    exist[aa] = 1;
                }
            }
        }
        set<int> t;
        rep(j, 1, n+1){
            if(exist[j]) t.insert(j);
        }
        if(t.size() == n) ans++;
    }

    cout << ans << endl;
    
    return 0;
}