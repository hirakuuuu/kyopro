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
    int h, w; cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, 0, h) rep(j, 0, w){
        cin >> a[i][j];
    }
    // if(h < w){
    //     vector<vector<int>> a_(w, vector<int>(h));
    //     rep(i, 0, w){
    //         rep(j, 0, h){
    //             a_[i][j] = a[j][i];
    //         }
    //     }
    //     swap(a, a_);
    //     swap(h, w);
    // }

    // 各行の最大値，最小値を調べる
    // 全部 0 の行は気にしないでよい
    vector<int> mx(h, -IINF), mi(h, IINF);
    rep(i, 0, h){
        rep(j, 0, w){
            if(a[i][j] == 0) continue;
            chmax(mx[i], a[i][j]);
            chmin(mi[i], a[i][j]);
        }
    }

    bool ok = true;
    // 各行の区間が両端いがいでかぶっていたらだめ
    vector<int> ind(h);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int i, int j){
        if(mi[i] == mi[j]) return mx[i] < mx[j];
        return mi[i] < mi[j];
    });
    rep(i, 0, h-1){
        if(mi[ind[i+1]] == IINF) continue;
        if(mx[ind[i]] <= mi[ind[i+1]]) continue;
        ok = false;
    }
    if(!ok){
        cout << "No" << endl;
        return 0;
    }

    vector<vector<int>> g(w+h*w);
    int v_id = w;
    vector<int> indeg(w+h*w);
    rep(i, 0, h){
        vector<pair<int, int>> val(w);
        rep(j, 0, w){
            val[j] = {a[i][j], j};
        }
        sort(val.begin(), val.end());
        rep(j, 0, w-1){
            if(val[j].first == 0) continue;
            if(val[j].first != val[j+1].first){
                rrep(k, j, 0){
                    if(val[k].first != val[j].first) break;
                    g[val[k].second].push_back(v_id);
                    indeg[v_id]++;
                }
                rep(k, j+1, w){
                    if(val[k].first != val[j+1].first) break;
                    g[v_id].push_back(val[k].second);
                    indeg[val[k].second]++;
                }
                v_id++;
            }
        }
    }
    queue<int> que;
    rep(i, 0, w+h*w){
        if(indeg[i] == 0) que.push(i);
    }
    int cnt = 0;
    while(!que.empty()){
        cnt++;
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            indeg[nq]--;
            if(indeg[nq] == 0) que.push(nq);
        }
    }
    if(cnt == w+h*w){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }




    
    return 0;
}