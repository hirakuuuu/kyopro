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
    ll x, y, z, k; cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, 0, x) cin >> a[i];
    rep(i, 0, y) cin >> b[i];
    rep(i, 0, z) cin >> c[i];

    vector<ll> ab;
    rep(i, 0, x){
        rep(j, 0, y) ab.push_back(a[i]+b[j]);
    }
    sort(ab.begin(), ab.end());
    reverse(ab.begin(), ab.end());
    sort(c.begin(), c.end());

    vector<ll> abc;    
    rep(i, 0, min(3001, (int)ab.size())){
        rep(j, 0, z){
            abc.push_back(ab[i]+c[j]);
        }
    }

    sort(abc.begin(), abc.end());
    reverse(abc.begin(), abc.end());

    rep(i, 0, k){
        cout << abc[i] << '\n';
    }


    return 0;
}