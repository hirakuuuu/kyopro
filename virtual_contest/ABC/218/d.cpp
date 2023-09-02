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
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    map<pair<int, int>, bool> m;
    rep(i, 0, n){
        cin >> p[i].first >> p[i].second;
        m[p[i]] = true;
    }
    
    int ans = 0;
    rep(i, 0, n){
        rep(j, i+1, n){
            if(p[i].first == p[j].first || p[i].second == p[j].second) continue;
            if(m[{p[i].first, p[j].second}] && m[{p[j].first, p[i].second}]) ans++;
        }
    }
    cout << ans/2 << endl;
    return 0;
}