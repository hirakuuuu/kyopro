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

// 座標圧縮
void comp(vector<int>&a){
  set<int>s(a.begin(),a.end());
  map<int,int>d;
  int cnt=0;
  for(auto x:s)d[x]=cnt++;
  for(auto&x:a)x=d[x];
}

int main(){
    int h, w, n; cin >> h >> w >> n;
    vector<int> r(n), c(n), a(n);
    map<int, vector<int>> mp;
    rep(i, 0, n){
        cin >> r[i] >> c[i] >> a[i];
        mp[a[i]].push_back(i);
    }
    vector<int> dp(n);
    vector<int> rmax(200005), cmax(200005);
    for(auto itr = mp.rbegin(); itr != mp.rend(); itr++){
        for(auto i: itr->second) dp[i] = max(rmax[r[i]], cmax[c[i]]); 
        for(auto i: itr->second) chmax(rmax[r[i]], dp[i]+1); 
        for(auto i: itr->second) chmax(cmax[c[i]], dp[i]+1); 
    }
    rep(i, 0, n) cout << dp[i] << endl;
    return 0;
}