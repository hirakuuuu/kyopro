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
// https://atcoder.jp/contests/abc327/tasks/abc327_c

int main(){
    vector<vector<int>> a(9, vector<int>(9));
    rep(i, 0, 9){
        rep(j, 0, 9){
            cin >> a[i][j];
        }
    }

    bool f = true;

    rep(i, 0, 9){
        set<int> s;
        rep(j, 0, 9){
            s.insert(a[i][j]);
        }
        if(s.size() != 9) f = false;
    }
    rep(j, 0, 9){
        set<int> s;
        rep(i, 0, 9){
            s.insert(a[i][j]);
        }
        if(s.size() != 9) f = false;
    }
    rep(i, 0, 9){
        set<int> s;
        rep(j, 0, 9){
            s.insert(a[(i/3)*3+j/3][(i%3)*3+j%3]);
        }
        if(s.size() != 9) f = false;
    }

    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}