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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}



int main(){
    int n, q; cin >> n >> q;
    vector<tuple<ll, int, int>> queri(q);
    rep(i, 0, q){
        int l, r; cin >> l >> r;
        l--;
        ll c; cin >> c;
        queri[i] = {c, l, r};
    }
    sort(queri.begin(), queri.end());
    ll ans = 0, e = 0;

    set<pair<int, int>> s;
    s.insert({-1, 0});
    s.insert({n, n+1});
    rep(i, 0, n) s.insert({i, i+1});
    rep(i, 0, q){
        auto [c, l, r] = queri[i];
        ll cnt = 0;
        
        // [l, r) が含まれてるやつで最初の区間にしないといけない（ここの処理で沼っていた）
        auto itr = prev(s.upper_bound({l, r}));
        if((*itr).second <= l) itr++;
        pair<int, int> tmp = *itr;
        int nl = tmp.first, nr = tmp.second;
        while(tmp.first < r){
            nr = tmp.second;
            // erase に iterator を指定すると, その次の iterator が返ってくる
            // 値を指定すると, 削除された要素の個数が返ってくる
            s.erase(tmp);
            tmp = *s.upper_bound(tmp);
            cnt++;
        }
        s.insert({nl, nr});
        ans += c*cnt;
        e += cnt;

        // cout << nl << ' ' << nr << endl;
        // for(auto [cl, cr]: s){
        //     cout << "{" << cl << ", " << cr << "}" << ' ';
        // }
        // cout << endl;
        // cout << ans << ' ' << e << endl;
    }
    if(s.size() != 3 || e != n+q-1) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}