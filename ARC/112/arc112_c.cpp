#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(ll i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc112/tasks/arc112_c

int main(){
    int n; cin >> n;
    vector<int> parent(n+1), indegree(n+1);
    vector<vector<int>> child(n+1);
    vector<vector<int>> score(n+1, vector<int>(3));
    rep(i, 2, n+1){
        cin >> parent[i];
        indegree[parent[i]]++;
        child[parent[i]].push_back(i);
    }

    queue<int> node;
    rep(i, 1, n+1){
        if(!child[i].size()) node.push(i);
    }

    while(!node.empty()){
        int p = node.front(); node.pop();
        vector<vector<int>> tmp;
        vector<pii> n_even, p_even, odd;
        for(auto c: child[p]){
            if(score[c][2]) odd.push_back({score[c][0]-score[c][1], score[c][1]});
            else if(score[c][0]-score[c][1] < 0) n_even.push_back({score[c][0]-score[c][1], score[c][1]});
            else p_even.push_back({score[c][0]-score[c][1], score[c][1]});
        }
        int f = 0;
        // 根のコイン
        score[p][0]++;
        // 負かつ偶数
        for(auto ne: n_even){
            score[p][0] += ne.first+ne.second;
            score[p][1] += ne.second;
        }
        // 奇数
        sort(odd.begin(), odd.end());
        for(auto o: odd){
            score[p][f] += o.first+o.second;
            score[p][1-f] += o.second;
            f = 1-f;
        }
        // 正かつ偶数
        for(auto pe: p_even){
            score[p][f] += pe.first+pe.second;
            score[p][1-f] += pe.second;
        }

        // 子どもの数の偶奇
        score[p][2] = 1-f;

        indegree[parent[p]]--;
        if(p != 1 && !indegree[parent[p]]){
            node.push(parent[p]);
        }
        // cout << p;
        // rep(i, 0, 3) cout << ' ' << score[p][i];
        // cout << endl;
    }
    cout << score[1][0] << endl;
    return 0;
}