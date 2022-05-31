#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc215/tasks/abc215_d

vector<int> e(100005), p(100005);
void init_p(){
    rep(i, 2, 100005){
        if(e[i] == 0){
            p[i] = 1;
            for(int j = i; j <= 100005; j += i) e[j] = 1;
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    init_p();
    vector<int> a(n), b(100005), c, d(100005);
    rep(i, 0, n){
        cin >> a[i];
        for(int j = 1; j*j <= a[i]; j++){
            if(a[i]%j == 0){
                if(d[j] == 0 and p[j]){
                    c.push_back(j);
                    d[j] = 1;
                }
                if(d[a[i]/j] == 0 and p[a[i]/j]){
                    c.push_back(a[i]/j);
                    d[a[i]/j] = 1;
                }
            }
        }
    }
    vector<int> ans;

    for(auto cc: c){
        for(int j = cc; j <= m; j += cc) b[j] = 1;
    }

    rep(i, 1, m+1){
        if(b[i] == 0){
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for(auto aa: ans){
        cout << aa << endl;
    }
    return 0;
}