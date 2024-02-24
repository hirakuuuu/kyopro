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
void comp(vector<ll>&a){
  set<ll>s(a.begin(),a.end());
  map<ll,ll>d;
  ll cnt=1;
  for(auto x:s)d[x]=cnt++;
  for(auto&x:a)x=d[x];
}

int main(){
    ll h, w, n; cin >> h >> w >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    comp(a);
    comp(b);
    rep(i, 0, n){
        cout << a[i] << ' ' << b[i] << endl;
    }
    
    
    return 0;
}