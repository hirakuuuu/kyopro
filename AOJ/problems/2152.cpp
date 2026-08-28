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
    while(true){
        int n; cin >> n;
        if(n == 0) break;

        set<tuple<ll, ll, ll>> s;
        s.insert({0, 1e9+1, -1});
        s.insert({1e9+1, 1e9+1, -1});
        unordered_map<int, set<pair<ll, ll>>> lrs;
        lrs[-1].insert({0, 1e9+1});
        queue<pair<ll, ll>> q1, q2;
        while(n--){
            char t; cin >> t;
            if(t == 'W'){
                ll x, y; cin >> x >> y;
                
                for(auto [l, r]: lrs[-1]){
                    if(r-l > y){
                        s.erase({l, r, -1});
                        q1.push({l, r});
                        s.insert({l, l+y, x});
                        lrs[x].insert({l, l+y});
                        if(l+y < r){
                            s.insert({l+y, r, -1});
                            q2.push({l+y, r});
                        }
                        y = 0;
                    }else{
                        s.erase({l, r, -1});
                        q1.push({l, r});
                        s.insert({l, r, x});
                        lrs[x].insert({l, r});
                        y -= r-l;
                    }
                    if(y == 0) break;
                }

                while(!q1.empty()){
                    lrs[-1].erase(q1.front()), q1.pop();
                }
                while(!q2.empty()){
                    lrs[-1].insert(q2.front()), q2.pop();
                }
            }else if(t == 'D'){
                ll x; cin >> x;
                for(auto [l, r]: lrs[x]){
                    s.erase({l, r, x});
                    s.insert({l, r, -1});
                    lrs[-1].insert({l, r});
                }
                lrs[x].clear();
            }else if(t == 'R'){
                ll x; cin >> x;
                auto [_, __, ans] = *prev(s.lower_bound({x+1, x+1, -1}));
                cout << ans << endl;
            }
        }
        cout << endl;
    }
    return 0;
}