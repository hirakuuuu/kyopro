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
    int t; cin >> t;
    while(t--){
        int n, d; cin >> n >> d;
        vector<int> a(n), b(n);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        
        queue<pair<int, int>> que;
        
        rep(i, 0, n){
            que.push({i, a[i]});
            int c = b[i];
            while(c){
                if(que.front().second <= c){
                    c -= que.front().second;
                    que.pop();
                }else{
                    que.front().second -= c;
                    c = 0;
                }
            }
            while(!que.empty() && que.front().first <= i-d) que.pop();
        }
        ll ans = 0;
        while(!que.empty()) ans += (ll)que.front().second, que.pop();
        cout << ans << endl;
    }
    return 0;
}