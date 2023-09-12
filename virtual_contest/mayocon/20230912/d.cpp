#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;



int main(){
    int n, k; cin >> n >> k;
    vector<int> p(n);
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
    }

    vector<int> ans(n, -1);
    vector<pair<int, int>> par(n, {-1, 1});
    set<int> s;
    rep(i, 0, n){
        auto itr = s.lower_bound(p[i]);
        if(itr != s.end()){
            par[p[i]] = {*itr, par[*itr].second+1};
            s.erase(itr);
 
        }
        if(par[p[i]].second == k){
            int tmp = p[i];
            ans[tmp] = i+1;
            while(par[tmp].first != -1){
                tmp = par[tmp].first;
                ans[tmp] = i+1;
            }
        }else{
            s.insert(p[i]);
        }
    }

    rep(i, 0, n){
        cout << ans[i] << '\n';
    }

    return 0;
}