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
    vector<pair<int, int>> path;
    rep(k, 2, n+2){
        if(k%2 == 0){
            rep(i, 1, n+1){
                int j = k-i;
                if(!inr(1, j, n+1)) continue;
                path.emplace_back(i, j); 
            }
        }else{
            rrep(i, n, 1){
                int j = k-i;
                if(!inr(1, j, n+1)) continue;
                path.emplace_back(i, j); 
            }
        }
    }

    int ans = (int)path.size()/2;
    cout << ans << endl;
    rep(i, 0, ans){
        cout << path[2*i].first << ' ' << path[2*i].second << ' ';
        cout << path[2*i+1].first << ' ' << path[2*i+1].second << endl;
    }
    
    return 0;
}