#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

void comp(vector<int>&a){
  set<int>s(a.begin(),a.end());
  map<int,int>d;
  int cnt=0;
  for(auto x:s)d[x]=cnt++;
  for(auto&x:a)x=d[x];
}


int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    comp(a);
    multiset<int> ms;
    rep(i, 0, n){
        auto itr = ms.upper_bound(-a[i]);
        if(itr != ms.end()) ms.erase(itr);
        ms.insert(-a[i]);
    }
    cout << ms.size() << endl;
    return 0;
}