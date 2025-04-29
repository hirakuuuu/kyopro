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
    int n, m, k; cin >> n >> m >> k;
    vector<int> c(n);
    rep(i, 0, n) cin >> c[i], c[i]--;

    vector<int> b(n);
    rep(i, 0, n) b[c[i]]++;
    auto calc_ball_cnt = [&](int id, int cnt_box) -> int {
        if(b[id] >= k*cnt_box) return k*cnt_box;
        return b[id];
    };

    int r = 0, sum = 0, tmp = 0;
    vector<int> cnt(n), ans(n);
    rep(i, 0, n){

        if(i > 0){
            sum -= (cnt[c[i-1]]+k-1)/k;
            tmp -= calc_ball_cnt(c[i-1], (cnt[c[i-1]]+k-1)/k);
            cnt[c[i-1]]--;
            sum += (cnt[c[i-1]]+k-1)/k;
            tmp += calc_ball_cnt(c[i-1], (cnt[c[i-1]]+k-1)/k);
        }

        while(r < n+i && (sum < m || cnt[c[r%n]]%k != 0)){
            sum -= (cnt[c[r%n]]+k-1)/k;
            tmp -= calc_ball_cnt(c[r%n], (cnt[c[r%n]]+k-1)/k);
            cnt[c[r%n]]++;
            sum += (cnt[c[r%n]]+k-1)/k;
            tmp += calc_ball_cnt(c[r%n], (cnt[c[r%n]]+k-1)/k);
            r++;
        }
        ans[i] = tmp;
    }
    rep(i, 0, n){
        cout << ans[i] << endl;
    }

    
    return 0;
}