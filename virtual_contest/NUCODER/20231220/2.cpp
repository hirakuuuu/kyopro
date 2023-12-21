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
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> p(n);
    rep(i, 0, m){
        int pre, year; cin >> pre >> year;
        pre--;
        p[pre].push_back({year, i});
    }
    rep(i, 0, n){
        sort(p[i].begin(), p[i].end());
    }

    vector<string> ans(m);
    rep(i, 0, n){
        rep(j, 0, p[i].size()){
            auto [y, ind] = p[i][j];
            string pid = to_string(i+1), iid = to_string(j+1);
            while(pid.size() <= 5) pid = '0'+pid;
            while(iid.size() <= 5) iid = '0'+iid;
            ans[ind] = pid+iid;
        }
    }

    rep(i, 0, m){
        cout << ans[i] << endl;
    }

    
    return 0;
}