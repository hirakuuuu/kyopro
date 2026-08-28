#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n; cin >> n;
    string s; cin >> s;
    ll allsame = 0;
    {
        map<tuple<int, int, int>, ll> cnt;
        cnt[{0, 0, 0}] = 1;
        vector<ll> c(3);
        rep(i, 0, n){
            c[s[i]-'A']++;
            allsame += cnt[{c[0]-c[1], c[1]-c[2], c[2]-c[0]}];
            cnt[{c[0]-c[1], c[1]-c[2], c[2]-c[0]}]++;
        }
    }
    // cout << allsame << endl;

    vector<ll> same(3);
    rep(k, 0, 3){
        map<ll, ll> cnt;
        cnt[0] = 1;
        vector<ll> c(3);
        rep(i, 0, n){
            c[s[i]-'A']++;
            same[k] += cnt[c[k]-c[(k+1)%3]];
            cnt[c[k]-c[(k+1)%3]]++;
        }
        same[k] -= allsame;
    }
    ll ans = n*(n+1)/2;
    ans -= allsame;
    rep(k, 0, 3) ans -= same[k];
    cout << ans << endl;
    return 0;
}