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
    int n, k; cin >> n >> k;
    vector<pair<int, int>> h(n);
    rep(i, 0, n){
        cin >> h[i].first >> h[i].second;
    }
    sort(h.begin(), h.end());
    vector<int> min_r(n+1, IINF);
    vector<int> min_id(n+1, n);
    rrep(i, n-1, 0){
        if(min_r[i+1] < h[i].second){
            min_r[i] = min_r[i+1];
            min_id[i] = min_id[i+1];
        }else{
            min_r[i] = h[i].second;
            min_id[i] = i;
        }
    }

    int ok = 0, ng = IINF;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        vector<int> nxt(n);
        rep(i, 0, n){
            int r = h[i].second;
            int pos = lower_bound(h.begin(), h.end(), make_pair(r+mid, -1))-h.begin();
            nxt[i] = min_id[pos];
            // cout << mid << ' ' << i << ' ' << nxt[i] << endl;
        }

        vector<vector<int>> dp(30, vector<int>(n+1));
        rep(i, 0, n){
            dp[0][i] = nxt[i];
        }
        rep(i, 0, 30){
            dp[i][n] = n;
        }
        rep(j, 1, 30){
            rep(i, 0, n){
                dp[j][i] = dp[j-1][dp[j-1][i]];
            }
        }

        vector<int> goal(n);
        iota(goal.begin(), goal.end(), 0);
        rep(i, 0, 30){
            if(((k-1)>>i)&1){
                rep(j, 0, n){
                    goal[j] = dp[i][goal[j]];
                }
            }
        }
        bool f = false;
        // cout << mid << ' ';
        rep(i, 0, n){
            // cout << goal[i] << ' ';
            if(goal[i] != n){
                f = true;
            }
        }
        // cout << endl;

        if(f) ok = mid;
        else ng = mid;
    } 

    if(ok == 0) ok = -1;
    cout << ok << endl;

    return 0;
}