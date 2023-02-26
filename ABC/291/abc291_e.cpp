#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc291/tasks/abc291_e

vector<vector<int>> g(200005);
vector<int> cnt_indegree(200005);

vector<int> topological_sort(int n){
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
        if(que.size() >= 2){
            cout << "No" << endl;
            exit(0);
        }
        int q = que.front(); que.pop();
        a_sorted.push_back(q);
        for(auto nq: g[q]){
            // 辺を削除
            cnt_indegree[nq]--;
            // 入次数が０になったらキューに追加
            if(cnt_indegree[nq] == 0) que.push(nq);
        }
    }

    // ソート済みの配列を返す
    return a_sorted;
}


int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        cnt_indegree[y]++;
    }

    vector<int> a = topological_sort(n);
    vector<int> ans(n);
    rep(i, 0, n){
        ans[a[i]] = i+1;
    }

    cout << "Yes" << endl;
    rep(i, 0, n){
        cout << ans[i] << ' ';
    }
  	cout << endl;

    
    return 0;
}