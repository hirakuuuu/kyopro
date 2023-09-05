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
    vector<pair<ll, ll>> c((1<<n));
    rep(i, 1, (1<<n)){
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(c.begin(), c.end());

    ll ans = 0;
    set<ll> s;
    s.insert(0);
    vector<bool> b((1<<n));
    rep(i, 1, (1<<n)){
        if(b[c[i].second]) continue;
        ans += c[i].first;
        set<ll> t = s;
        for(auto ss: s){
            ll tmp = ss^c[i].second;
            t.insert(tmp);
            b[tmp] = true;
        }
        swap(s, t);
    }
    cout << ans << endl;
    
    return 0;
}