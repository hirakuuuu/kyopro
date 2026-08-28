#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    vector<pair<ll, ll>> ab;
    ll base = 0;
    rep(i, 0, n){
        if(a[i] == 0) base += abs(b[i]);
        else{
            if(a[i] < 0) a[i] = -a[i], b[i] = -b[i];
            ab.push_back({a[i], b[i]});
        }
    }
    int m = ab.size();
    sort(ab.begin(), ab.end(), [](auto s, auto t){
        return s.second*t.first < s.first*t.second;
    });
    // rep(i, 0, m){
    //     cout << ab[i].first << ' ' << ab[i].second << endl;
    // }

    long double tmp = 0;
    rep(i, 0, m) tmp -= ab[i].first;
    long double now = 0;
    rep(i, 0, m){
        long double da = ab[i].first, db = ab[i].second;
        now += abs(da*ab[0].second/ab[0].first-db);
    }
    tmp += ab[0].first*2;
    long double ans = base+now;
    int ans_id = 0;
    rep(i, 1, m){
        long double gap = (long double)ab[i].second/ab[i].first-(long double)ab[i-1].second/ab[i-1].first;
        now += gap*tmp;
        if(ans > base+now){
            ans = base+now;
            ans_id = i;
        }
        tmp += ab[i].first*2;
    }

    // cout << ans_id << endl;
    mint q = mint(ab[ans_id].second)/ab[ans_id].first;
    cout << q.val() << endl;

    return 0;
}