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
    int n; cin >> n;
    set<tuple<ll, ll, ll>> b;
    b.insert({0, INF, 0});
    queue<tuple<ll, ll, ll>> q1;
    queue<tuple<ll, ll, ll>> q2;
    rep(i, 0, n){
        ll s, c; cin >> s >> c;
        s--;
        auto [pl, pr, pc] = *prev(b.lower_bound({s+1, s+1, 0}));
        b.erase({pl, pr, pc});
        if(pl != s) b.insert({pl, s, pc});
        b.insert({s, pr, pc});

        ll ans = -1;
        for(auto itr = b.lower_bound({s, -1, -1}); itr != b.end(); itr++){
            auto [l, r, col] = *itr;
            if(c == 0) break;
            q1.push({l, r, col});
            if(col == 1) continue;
            if(r-l < c){
                q1.push({l, r, col});
                c -= r-l;
            }else{
                q1.push({l, r, col});
                q2.push({s, l+c, 1});
                ans = l+c;
                if(l+c < r) q2.push({l+c, r, 0});
                c = 0;
            }
        }
        while(!q1.empty()){
            b.erase(q1.front()), q1.pop();
        }
        while(!q2.empty()){
            b.insert(q2.front()), q2.pop();
        }
        cout << ans << endl;
    }
    return 0;
}