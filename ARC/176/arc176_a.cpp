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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
(a[i]+b[i])%n が高々 m 個しかないので、(a[i]+b[i])%n = (i+j)%n を満たすマスをすべて塗ればよい
*/

int main(){
    int n, m; cin >> n >> m;
    set<int> s;
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        s.insert((a+b)%n);
    }

    rep(i, 0, n){
        if(s.size() < m){
            s.insert(i);
        }
    }

    vector<pair<int, int>> ans;
    for(auto ss: s){
        rep(i, 0, n){
            ans.push_back({i, (ss-i+n)%n});
        }
    }
    cout << ans.size() << endl;
    for(auto [x, y]: ans){
        cout << x+1 << ' ' << y+1 << '\n';
    }


    return 0;
}