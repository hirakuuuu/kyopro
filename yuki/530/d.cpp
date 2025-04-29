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

    int n, T; cin >> n >> T;
    vector<int> t(n-1);
    rep(i, 0, n-1) cin >> t[i];
    int k; cin >> k;
    vector<int> c(n);
    rep(i, 0, k){
        int x; cin >> x; x--;
        c[x] = 1;
    }

    queue<pair<int, int>> que;
    que.push({T, 0});
    int sum = 0;
    int last = T, cnt = 0;
    rep(i, 0, n-1){
        sum += t[i];
        // cout << que.front().first << ' ' << que.front().second << ' ' << sum << endl;
        while(!que.empty() && que.front().first <= sum){
            que.pop();
        }
        if(que.empty()) break;
        if(c[i+1]){
            que.push({last+10, cnt+1});
            cnt++;
            last += 10;
        }
    }

    if(que.empty()) cout << -1 << endl;
    else cout << que.front().second << endl;

    return 0;
}