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

int main(){
    int n, m; cin >> n >> m;
    vector<int> p(m), y(m);
    map<int, set<pii>> town;
    rep(i, 0, m){
        cin >> p[i] >> y[i];
        town[p[i]].insert({y[i], i});
    }

    map<int, bool> checked;
    vector<string> ans(m);
    rep(i, 0, m){
        if(checked[p[i]]) continue;
        checked[p[i]] = true;
        int x = 1;
        string str_p = to_string(p[i]);
        while(str_p.size() < 6) str_p = '0'+str_p;
        for(auto yi: town[p[i]]){
            string str_x = to_string(x);
            while(str_x.size() < 6) str_x = '0'+str_x;
            ans[yi.second] = str_p+str_x;
            x++;
        }
    }

    rep(i, 0, m){
        cout << ans[i] << endl;
    }


    
    return 0;
}