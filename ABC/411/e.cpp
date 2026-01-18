#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(6));
    priority_queue<pair<int, int>> que;
    rep(i, 0, n){
        rep(j, 0, 6){
            cin >> a[i][j];
            que.push({a[i][j], i});
        }
    }
    vector<int> cnt(n, 6);
    mint bunsi = mint(6).pow(n);
    mint bunbo = mint(6).pow(n);
    mint ans = 0;
    while(!que.empty()){
        auto [val, id] = que.top(); que.pop();
        bunsi /= cnt[id];
        ans += mint(val)*bunsi/bunbo;
        cnt[id]--;
        bunsi *= cnt[id];
    }
    cout << ans.val() << endl;
    return 0;
}