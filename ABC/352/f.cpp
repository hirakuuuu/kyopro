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
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c; a--, b--;
        g[b].push_back({a, c});
        g[a].push_back({b, -c});
    }

    vector<int> nums;
    vector<int> seen(n, -IINF);
    vector<vector<pair<int, int>>> bs;
    rep(i, 0, n){
        if(seen[i] != -IINF) continue;
        queue<int> que;
        que.push(i);
        seen[i] = 0;
        vector<pair<int, int>> bit = {{0, i}};
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto [nq, cost]: g[q]){
                if(seen[nq] != -IINF) continue;
                seen[nq] = seen[q]+cost;
                bit.push_back({seen[nq], nq});
                que.push(nq);
            }
        }
        sort(bit.begin(), bit.end());
        int tmp = 0;
        bs.push_back({});
        for(auto bb: bit){
            tmp += 1<<(bb.first-bit[0].first);
            bs.back().push_back({bb.first-bit[0].first, bb.second});
        }
        nums.push_back(tmp);
    }


    int k = (int)nums.size();
    vector dp(k, vector<vector<int>>(1<<n));
    rep(i, 0, n){
        if((nums[0]<<i) >= (1<<n)) break;
        dp[0][nums[0]<<i].push_back(i);
    }
    rep(i, 1, k){
        rep(j, 0, 1<<n){
            if(dp[i-1][j].empty()) continue;
            rep(l, 0, n){
                if((nums[i]<<l) >= (1<<n)) break;
                if(((nums[i]<<l)&j) == 0) dp[i][(nums[i]<<l)+j].push_back(l);
            }
        }
    }

    vector<int> ans(n, -1);
    vector<int> oks = {(1<<n)-1};
    rrep(i, k-1, 0){
        vector<int> noks;
        set<int> shifts;
        for(auto ok: oks){
            for(auto shift: dp[i][ok]){
                shifts.insert(shift);
                noks.push_back(ok-(nums[i]<<shift));
            }
        }
        assert(!shifts.empty());
        if(shifts.size() == 1){
            // 一意
            int shift = *shifts.begin();
            for(auto [bit, v]: bs[i]){
                ans[v] = bit+shift+1;
            }
        }
        sort(noks.begin(), noks.end());
        noks.erase(unique(noks.begin(), noks.end()), noks.end());
        swap(oks, noks);
    }

    rep(i, 0, n){
        cout << ans[i] << ' ';
    }
    cout << endl;




    return 0;
}