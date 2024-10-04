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
    int h, w, q; cin >> h >> w >> q;
    vector<set<int>> R(h), C(w);
    rep(i, 0, h){
        R[i].insert(-1);
        R[i].insert(w);
    }
    rep(j, 0, w){
        C[j].insert(-1);
        C[j].insert(h);
    }
    rep(i, 0, h){
        rep(j, 0, w){
            R[i].insert(j);
            C[j].insert(i);
        }
    }
    while(q--){
        int r, c; cin >> r >> c;
        r--, c--;
        if(R[r].find(c) != R[r].end()){
            R[r].erase(c);
            C[c].erase(r);
        }else{
            vector<pair<int, int>> del;
            auto itr = R[r].upper_bound(c);
            if(*itr != w) del.push_back({r, *itr});
            if(*prev(itr) != -1) del.push_back({r, *prev(itr)});
            itr = C[c].upper_bound(r);
            if(*itr != h) del.push_back({*itr, c});
            if(*prev(itr) != -1) del.push_back({*prev(itr), c});
            
            for(auto [x, y]: del){
                R[x].erase(y);
                C[y].erase(x);
            }
        }
    }
    int ans = 0;
    rep(i, 0, h){
        ans += (int)R[i].size()-2;
    }
    cout << ans << endl;
    
    return 0;
}