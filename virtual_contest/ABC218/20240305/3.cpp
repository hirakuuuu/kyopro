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
// 

int main(){
    int n; cin >> n;
    vector<string> s(n), t(n);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) cin >> t[i];
    set<pair<int, int>> ps, pt;
    rep(i, 0, n){
        rep(j, 0, n){
            if(s[i][j] == '#') ps.insert({i, j});
            if(t[i][j] == '#') pt.insert({i, j});
        }
    }

    rep(_, 0, 4){
        // 左の列で一番上のマスを合わせる
        set<pair<int, int>> ns;
        pair<int, int> fs = *ps.begin(), ft = *pt.begin();
        pair<int, int> offset = {ft.first-fs.first, ft.second-fs.second};
        for(auto [x, y]: ps){
            ns.insert({x+offset.first, y+offset.second});
        }
        if(ns == pt){
            cout << "Yes" << endl;
            return 0;
        }


        // 90度回転
        set<pair<int, int>> s_;
        for(auto [x, y]: ps){
            s_.insert({y, n-x-1});
        }
        swap(s_, ps);
    }
    cout << "No" << endl;
    
    return 0;
}