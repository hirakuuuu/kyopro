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
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int q; cin >> q;
    vector<tuple<int, int, int, int>> queri(q);
    rep(i, 0, q){
        int t; cin >> t;
        if(t == 1){
            int l, r, x; cin >> l >> r >> x;
            l--;
            queri[i] = {t, l, r, x};
        }else{
            int id; cin >> id;
            id--;
            queri[i] = {t, id, -1, -1};
        }
    }

    // priority_queue 2つで消せる priority_queue が作れる
    // 追加するときは１つ目に, 削除するときは２つ目にいれる
    // 最大値を取り出すときに, 両者の max が一致していたら, 両方pop
    // そうでなければそれを最大値とする
    vector<pair<priority_queue<int>, priority_queue<int>>> node(2*n);
    rep(i, 0, n) node[i+n].first.push(a[i]);

    // 追加
    auto add{[](int x) {return [x](auto &pq) { return pq.first.push(x); }; }};
    // 削除
    auto erase{[](int x) {return [x](auto &pq) { return pq.second.push(x); }; }};

    // 最大値が存在すればそれを, そうでなければ０を返す
    auto top_or_zero = [&](pair<priority_queue<int>, priority_queue<int>> &pq) -> int {
        int res = 0;
        while(!pq.second.empty() && pq.first.top() == pq.second.top()){
            pq.first.pop(); pq.second.pop();
        }
        if(!pq.first.empty()) res = pq.first.top();
        return res;
    };

    // 区間更新
    auto range_update = [&](int l, int r, const auto &callback) -> void {
        l += n;
        r += n;
        while(l != r){
            if(l&1) callback(node[l++]);
            if(r&1) callback(node[--r]);
            l /= 2;
            r /= 2;
        }
    };

    // 1点取得
    auto point_access = [&](int i, const auto &mapping, const auto &op) -> int {
        i += n;
        int res = 0;
        while(i){
            res = op(res, mapping(node[i]));
            i /= 2;
        }
        return res;
    };

    rep(i, 0, q){
        auto [t, l, r, x] = queri[i];
        if(t == 1){
            range_update(l, r, add(x));
        }else if(t == 2){
            int id = l;
            auto [_, l, r, x] = queri[id];
            range_update(l, r, erase(x));
        }else{
            int id = l;
            cout << point_access(id, top_or_zero, [](auto a, auto b){return max(a, b);}) << endl;
        }
    }
    
    return 0;
}