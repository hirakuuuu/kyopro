#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long

/*
有向グラフの順序関係を崩さないようにソートする
1. 各ノードの入次数を数える
2. 入次数が０であればキューに追加
3. キューからノードを取り出し、そのノードから出ている辺を削除
4. ２に戻ってキューがからになるまで繰り返す

孵ってくる配列のサイズで閉路があるかどうかも検出できる
*/

vector<vector<int>> g(100005);
vector<int> cnt_indegree(100005);
int n, m;

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
    cin >> n >> m;
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        cnt_indegree[y]++;
    }

    vector<int> b = topological_sort(n);

    if(b.size() != n){
        cout << "Find circuit!" << endl;
    }else{
        cout << "No circuit!" << endl;
    }

    return 0;
}