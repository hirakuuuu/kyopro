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
    int n, k, x; cin >> n >> k >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    priority_queue<pair<ll, vector<int>>> pq;
    {
        vector<int> cnt(n);
        cnt[0] = k;
        pq.push({a[0]*k, cnt});
    }

    map<vector<int>, int> memo;
    rep(_, 0, x){
        auto [score, cnt] = pq.top(); pq.pop();
        cout << score << endl;
        // rep(i, 0, n){
        //     cout << cnt[i] << ' ';
        // }
        // cout << endl;
        rep(i, 0, n-1){
            if(cnt[i] > 0){
                ll nscore = score-a[i]+a[i+1];
                vector<int> ncnt = cnt;
                ncnt[i]--, ncnt[i+1]++;
                if(memo.count(ncnt)) continue;
                pq.push({nscore, ncnt});
                memo[ncnt] = 1;
            }
        }
    }

    return 0;
}