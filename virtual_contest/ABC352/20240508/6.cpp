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

// 問題
// 

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, -c});
        g[b].push_back({a, c});
    }
    vector<vector<int>> a;
    vector<int> bit;
    vector<int> seen(n, IINF);
    rep(i, 0, n){
        if(seen[i] != IINF) continue;
        seen[i] = 0;
        queue<int> que;
        que.push(i);
        set<pair<int, int>> s;
        s.insert({0, i});
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto [nq, cost]: g[q]){
                if(seen[nq] != IINF) continue;
                seen[nq] = seen[q]+cost;
                s.insert({seen[nq], nq});
                que.push(nq);
            }
        }
        vector<int> b(n, -1);
        int offset = (*s.begin()).first;
        for(auto [p, j]: s){
            b[p-offset] = j;
        }
        while(b.back() == -1) b.pop_back();
        a.push_back(b);
        int tmp = 0;
        rep(j, 0, b.size()){
            if(b[j] != -1){
                tmp += (1<<j);
            }
        }
        bit.push_back(tmp);
    }

    int cnt_one = 0;
    rep(i, 0, a.size()){
        if(a[i].size() == 1){
            cnt_one++;
        }
    }
    if(cnt_one >= 2){
        vector<vector<int>> a_;
        vector<int> bit_;
        rep(i, 0, a.size()){
            if(a[i].size() != 1){
                a_.push_back(a[i]);
                bit_.push_back(bit[i]);
            }
        }
        swap(a_, a);
        swap(bit_, bit);
    }

    vector<set<int>> l(a.size());
    auto f = [&](auto self, int pos, int tmp) -> bool {
        if(pos == a.size()){
            return true;
        }
        bool res = false;
        rrep(i, n-a[pos].size(), 0){
            int cur = (bit[pos]<<i);
            if((tmp&cur) > 0) continue;
            bool r = self(self, pos+1, tmp+cur);
            if(r){
                l[pos].insert(i); // i個ずらすだけなので、iで良い
                res = true;
            }
            // if(l[pos].size() >= 2) break;
        }
        return res;
    };
    f(f, 0, 0);
    vector<int> ans(n, -1);
    rep(i, 0, a.size()){
        assert(l[i].size() > 0);
        if(l[i].size() == 1){
            rep(j, 0, a[i].size()){
                if(a[i][j] != -1){
                    ans[a[i][j]] = j+(*l[i].begin())+1;
                }
            }
        }
    }
    rep(i, 0, n){
        cout << ans[i] << ' ';
    }
    cout << endl;

    
    return 0;
}