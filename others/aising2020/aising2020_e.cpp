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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> k(n), l(n), r(n);
        rep(i, 0, n) cin >> k[i] >> l[i] >> r[i];
        int nl = 0;
        rep(i, 0, n){
            if(l[i] >= r[i]) nl++;
        }

        ll ans = 0;
        vector<vector<vector<ll>>> score(2, vector<vector<ll>>(n+1));
        rep(i, 0, n){
            if(l[i] >= r[i]){
                score[0][min(nl, (int)k[i]-1)].push_back(l[i]-r[i]);
            }else{
                score[1][max(nl, (int)k[i])].push_back(r[i]-l[i]);
            }
            ans += min(l[i], r[i]);
        }
        priority_queue<ll, vector<ll>, greater<ll>> que;
        rep(i, 0, n){
            for(auto ss: score[0][i]){
                que.push(ss);
            }
            while(que.size() > i+1){
                que.pop();
            }
        }
        while(!que.empty()){
            ans += que.top(); que.pop();
        }
        rrep(i, n-1, 0){
            for(auto ss: score[1][i]){
                que.push(ss);
            }
            while(que.size() > n-i){
                que.pop();
            }
        }
        while(!que.empty()){
            ans += que.top(); que.pop();
        }
        cout << ans << endl;
    }
    
    return 0;
}