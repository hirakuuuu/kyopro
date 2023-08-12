#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc314/tasks/abc314_b

int main(){
    int n; cin >> n;
    vector<int> c(n);
    vector<vector<int>> a(n);
    rep(i, 0, n){
        cin >> c[i];
        rep(j, 0, c[i]){
            int b; cin >> b;
            a[i].push_back(b);
        }
    }

    int x; cin >> x;
    int min_alen = 100100;
    rep(i, 0, n){
        bool f = false;
        rep(j, 0, c[i]){
            if(a[i][j] == x) f = true;
        }

        if(f){
            chmin(min_alen, a[i].size());
        }
    }

    vector<int> ans;
    rep(i, 0, n){
        bool f = false;
        rep(j, 0, c[i]){
            if(a[i][j] == x) f = true;
        }

        if(f && a[i].size() == min_alen){
            ans.push_back(i+1);
        }
    }

    cout << ans.size() << endl;
    for(auto aa: ans){
        cout << aa << ' ';
    }
    cout << endl;
    
    return 0;
}