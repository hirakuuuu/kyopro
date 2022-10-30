#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl "\n"
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc174/tasks/abc174_f

// クエリ先読み、フェニック木

// フェニック木
vector<int> dat(500005);
void add(int i, int x, int n){
    while(i <= n){
        dat[i] += x;
        i += i&-i;
    }
}

int sum_i(int i){
    int s = 0;
    while(i){
        s += dat[i];
        i -= i&-i;
    }
    return s;
}

int sum_lr(int l, int r){
    return sum_i(r)-sum_i(l-1);
}

int main(){
    int n, q; cin >> n >> q;
    vector<int> c(n+1), a(n+1), ans(q);
    vector<vector<int>> ql(n+1), qid(n+1);
    rep(i, 1, n+1) cin >> c[i];

    rep(i, 0, q){
        int l, r; cin >> l >> r;
        ql[r].push_back(l);
        qid[r].push_back(i);
    }

    rep(i, 1, n+1){
        if(a[c[i]]) add(a[c[i]], -1, n);
        add(i, 1, n);
        a[c[i]] = i;
        rep(j, 0, ql[i].size()){
            ans[qid[i][j]] = sum_lr(ql[i][j], i);
        }
    }
    rep(i, 0, q){
        cout << ans[i] << endl;
    }
    
    return 0;
}