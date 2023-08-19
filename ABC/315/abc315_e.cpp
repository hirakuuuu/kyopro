#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc315/tasks/abc315_e

int main(){
    int n; cin >> n;
    vector<int> c(n);
    vector<vector<int>> p(n);
    rep(i, 0, n){
        cin >> c[i];
        rep(j, 0, c[i]){
            int q; cin >> q;
            q--;
            p[i].push_back(q);
        }
    }

    queue<int> que;
    que.push(0);
    vector<bool> read(n);
    vector<int> ind(n);
    vector<vector<int>> np(n);
    read[0] = true;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto pp: p[q]){
            ind[q]++;
            np[pp].push_back(q);
            if(read[pp]) continue;
            read[pp] = true;
            que.push(pp);
        }
    }


    vector<int> ans;
    queue<int> topo;
    rep(i, 0, n){
        if(ind[i] == 0 && np[i].size()) topo.push(i);
    }
    while(!topo.empty()){
        int t = topo.front(); topo.pop();
        ans.push_back(t);
        for(auto pp: np[t]){
            ind[pp]--;
            if(ind[pp] == 0) topo.push(pp);
        }
    }

    for(auto aa: ans){
        if(aa == 0) continue;
        else cout << aa+1 << ' ';
    }
    cout << endl;



    
    return 0;
}