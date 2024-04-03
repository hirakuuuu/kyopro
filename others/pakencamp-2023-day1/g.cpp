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
// https://atcoder.jp/contests/pakencamp-2023-day1/tasks/g

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> p, m;
    multiset<ll> s, t;
    s.insert(a[0]);
    rep(i, 1, n) t.insert(a[i]);
    ll ans = 0;
    while(!t.empty()){
        ll sl = *s.begin(), sr = *s.rbegin();
        ll tl = *t.begin(), tr = *t.rbegin();
        ll tmp = min({sl*tl, sl*tr, sr*tl, sr*tr});
        ans += tmp;
        if(tmp == sl*tl || tmp == sr*tl){
            t.erase(t.find(tl));
            s.insert(tl);
        }else{
            t.erase(t.find(tr));
            s.insert(tr);
        }
    }
    cout << ans << endl;


    
    return 0;
}