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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(m);
    vector<vector<int>> g(n);
    vector<int> cnt_indegree(n);

    rep(i, 0, m){
        int k; cin >> k;
        a[i].resize(k);
        rep(j, 0, k){
            int A; cin >> A;
            A--;
            a[i][j] = A;
        }
        rep(j, 0, k-1){
            g[a[i][j]].push_back(a[i][j+1]);
            cnt_indegree[a[i][j+1]]++;
        }
    }

    // ソートして格納する配列
    vector<int> a_sorted;
    queue<int> que;

    // 入次数０のノードをキューに追加
    rep(i, 0, n){
        if(cnt_indegree[i] == 0){
            que.push(i);
        }
    }

    // 入次数が０になったノードから配列に格納
    while(!que.empty()){
        int q = que.front(); que.pop();
        a_sorted.push_back(q);
        for(auto nq: g[q]){
            // 辺を削除
            cnt_indegree[nq]--;
            // 入次数が０になったらキューに追加
            if(cnt_indegree[nq] == 0) que.push(nq);
        }
    }

    if(a_sorted.size() == n){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}