#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc289/tasks/abc289_g


int main(){
    ll n, m; cin >> n >> m;
    vector<ll> B(n);
    rep(i, 0, n) cin >> B[i];
    sort(B.rbegin(), B.rend());
    vector<tuple<ll, ll, ll>> b_convex;
    b_convex.emplace_back(0, 1, B[0]);
    rep(i, 1, n){
        ll x, a = i+1, b = a*B[i];
        ll x_prev, a_prev, b_prev;
        do{
            tie(x_prev, a_prev, b_prev) = b_convex.back();
            x = max(0LL, (b_prev-b+a-a_prev-1)/(a-a_prev));
            if(x_prev < x) break;
            b_convex.pop_back();
        }while(!b_convex.empty());
        b_convex.emplace_back(x, a, b);
    }

    rep(i, 0, m){
        ll c; cin >> c;
        auto [_, a, b] = *prev(upper_bound(b_convex.begin(), b_convex.end(), make_tuple(c+1, 0LL, 0LL)));
        cout << a*c+b << endl;
    }

    
    return 0;
}