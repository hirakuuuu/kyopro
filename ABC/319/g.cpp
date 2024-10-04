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

int main(){
    int n, m; cin >> n >> m;
    vector<int> u(m), v(m);
    vector<vector<int>> ng(n);
    map<pair<int, int>, bool> deleted;
    rep(i, 0, m){
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        ng[u[i]].push_back(v[i]);
        ng[v[i]].push_back(u[i]);
        deleted[{u[i], v[i]}] = deleted[{v[i], u[i]}] = true;
    }

    int thl = (int)sqrt(200000);
    thl *= 2;
    // 連結であれば、長さthl以下のパスが残るはず
    auto calc_dist_and_cnt = [&](int s) -> pair<vector<int>, vector<mint>> {
        vector<int> dist(n, IINF);
        vector<mint> cnt(n);
        dist[s] = 0, cnt[s] = 1;
        int pre = 1, pre_ = pre;
        mint tot = 1, tot_ = tot;
        rep(i, 0, thl){
            pre_ = 0;
            tot_ = 0;
            rep(j, 0, n){
                if(dist[j] != IINF) continue;
                int del_cnt = 0;
                mint tmp = tot;
                for(auto k: ng[j]){
                    // 削除された辺を除く
                    if(dist[k] == i){
                        tmp -= cnt[k];
                        del_cnt++;
                    }
                }
                if(del_cnt != pre){
                    dist[j] = i+1;
                    cnt[j] = tmp;
                    pre_++;
                    tot_ += cnt[j];
                }
            }
            pre = pre_;
            tot = tot_;
        }
        return {dist, cnt};
    };

    pair<vector<int>, vector<mint>> l = calc_dist_and_cnt(0);
    if(l.first[n-1] == IINF){
        cout << -1 << endl;
    }else{
        cout << l.second[n-1].val() << endl;
    }
    return 0;
}