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
// https://atcoder.jp/contests/agc065/tasks/agc065_a

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    ll ans = 0;
    ll d = 0;
    vector<ll> m, M;
    map<ll, ll> cnt;
    rep(i, 0, n) cnt[a[i]]++;
    set<ll> sa;
    rep(i, 0, n) sa.insert(a[i]);
    ll mx = 0;
    while(!sa.empty()){
        d += sa.size()-1;
        set<ll> sb = sa;
        M.push_back(*sb.rbegin());
        m.push_back(*sb.begin());
        // cout << M.back() << ' ' << m.back() << endl;
        ll pre = *sb.begin();
        for(auto bb: sb){
            chmax(mx, bb-pre);
            pre = bb;
            cnt[bb]--;
            if(cnt[bb] == 0) sa.erase(bb);
        }
    }
    ans = max(m.back()-M.back()+d*k, mx+(d-1)*k);
    cout << ans << endl;
    return 0;
}