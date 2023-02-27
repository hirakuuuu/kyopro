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
// https://atcoder.jp/contests/abc108/tasks/arc102_b

int main(){
    int l; cin >> l;
    int n = 0;
    int l_c = l;
    while(l_c != 0){
        l_c /= 2;
        n++;
    }

    vector<vector<int>> ans;
    rep(i, 1, n){
        ans.push_back({i, i+1, 0});
        ans.push_back({i, i+1, (1<<(n-i-1))});
    }

    rep(i, 0, n-1){
        if((l&(1<<i)) > 0){
            l -= (1<<i);
            ans.push_back({1, n-i, l});
        }
    }

    cout << n << ' ' << ans.size() << endl;
    for(const auto &a: ans){
        rep(i, 0, 3){
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    
    return 0;
}