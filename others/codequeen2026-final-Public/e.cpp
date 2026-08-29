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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> l(n), r(n);
    vector<pair<int, int>> h(n);
    rep(i, 0, n){
        cin >> l[i] >> r[i];
        h[i] = {l[i], r[i]};
    }
    sort(h.begin(), h.end());
    int pos = 0;
    int ans = 0;
    while(pos < n){
        int th = h[pos].first;
        int iter = 0;
        while(pos < n){
            iter++;
            int cnt = 0, mx = 0;
            while(pos < n && h[pos].first <= th){
                cnt++;
                chmax(mx, h[pos].second);
                pos++;
            }
            if(cnt == 0) break;
            // cout << pos << ' ' << cnt << ' ' << mx << ' ' << th << endl;
            if(iter >= 2 && mx <= th){
                ans += cnt;
                break;
            }
            ans += cnt-1;
            th = mx;
        }
    }
    cout << ans << endl;
    return 0;
}