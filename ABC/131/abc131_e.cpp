#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
// constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

/*
連結なので、m >= n-1
少なくともｍこの頂点対は最短距離が２ではないので、k >= n*(n-1)/2-m
スターグラフにすると、(n-1)*(n-2)/2が達成可能
完全グラフにすると、0が達成可能
完全グラフから適切に辺を取り除いていくとできる？
*/

int main(){
    int n, k; cin >> n >> k;
    int total = n*(n-1)/2-(n-1);
    if(total < k){
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int, int>> edge;
    rep(i, 2, n+1){
        edge.push_back({1, i});
    }
    rep(i, 2, n+1){
        if(edge.size()-(n-1) == total-k) break; 
        rep(j, i+1, n+1){
            if(edge.size()-(n-1) == total-k) break; 
            edge.push_back({i, j});
        }
    }
    cout << edge.size() << endl;
    for(auto [p, q]: edge){
        cout << p << ' ' << q << endl;
    }

    return 0;
}