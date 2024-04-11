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

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> lr(m);
    rep(i, 0, m){
         cin >> lr[i].first >> lr[i].second;
         lr[i].first--, lr[i].second--;
    }
    sort(lr.begin(), lr.end());
    vector<vector<int>> l
    rep(i, 0, m){
        int L, R; cin >> L >> R;
        L--, R--;
        l[R].push_back(L);
        r[L].push_back(R);
    }


    
    return 0;
}