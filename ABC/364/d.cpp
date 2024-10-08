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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    vector<tuple<int, int, int>> queri(q);
    rep(i, 0, q){
        int b, k; cin >> b >> k;
        queri[i] = {b, k, i};
    }
    sort(queri.begin(), queri.end());

    vector<int> l, r = a;
    int sr = 0;
    vector<int> d(q);
    rep(i, 0, q){
        auto [b, k, id] = queri[i];
        while(sr < n && r[sr] <= b){
            l.push_back(r[sr]);
            sr++;
        }

        // 二分探索
        int ok = 0, ng = 1e9;
        while(ng-ok > 1){
            int mid = (ok+ng)/2;
            int cnt_l = l.end() - upper_bound(l.begin(), l.end(), b-mid);
            int cnt_r = lower_bound(r.begin()+sr, r.end(), b+mid)-r.begin()-sr;
            // cout << cnt_l << ' ' << cnt_r << endl;
            if(cnt_l+cnt_r >= k) ng = mid;
            else ok = mid;
        }
        d[id] = ok;
    }
    rep(i, 0, q){
        cout << d[i] << endl;
    }
    
    return 0;
}