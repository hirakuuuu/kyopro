#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc013/tasks/abc013_4

vector<int> init_t(vector<int> a, int n, int m, int d){
    vector<int> t(n);
    iota(t.begin(), t.end(), 0);
    rep(i, 0, m){
        swap(t[a[m-i-1]], t[a[m-i-1]+1]);
    }

    
    vector<int> res(n);
    iota(res.begin(), res.end(), 0);

    while(d > 0){
        if(d%2 == 1){
            rep(i, 0, n){
                res[i] = t[res[i]];
            }
        }
        d /= 2;

        // tを更新
        vector<int> t_(n);
        rep(i, 0, n){
            t_[i] = t[t[i]];
        }
        t = t_;
    }

    return res;
}

int main(){
    int n, m, d; cin >> n >> m >> d;
    vector<int> a(m);
    rep(i, 0, m){
        cin >> a[i];
        a[i]--;
    }

    vector<int> ans = init_t(a, n, m, d);
    rep(i, 0, n){
        cout << ans[i]+1 << endl;
    }


    
    return 0;
}