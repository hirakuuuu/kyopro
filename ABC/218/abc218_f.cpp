#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc218/tasks/abc218_f

vector<vector<int>> g(405, vector<int>(405, -1));

int main(){
    int n, m; cin >> n >> m;
    vector<int> s(m), t(m);
    rep(i, 0, m){
        cin >> s[i] >> t[i];
        s[i]--, t[i]--;
       g[s[i]][t[i]] = i;
    }

    vector<int> dist(n, -1);
    vector<pii> memo(n);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    while(!que.empty()){
        int q = que.front(); que.pop();
        rep(i, 0, n){
            if(dist[i] == -1 and g[q][i] != -1){
                dist[i] = dist[q]+1;
                memo[i] = {q, g[q][i]};
                que.push(i);
            }
        }
    }

    vector<int> sp;
    if(dist[n-1] != -1){
        int cur = n-1;
        while(cur != 0){
            sp.push_back(memo[cur].second);
            cur = memo[cur].first;
        }
    }


    vector<int> ans(m, dist[n-1]);
    for(const auto &e: sp){
        g[s[e]][t[e]] = -1;
        vector<int> dist_(n, -1);
        queue<int> que_;
        que_.push(0);
        dist_[0] = 0;
        while(!que_.empty()){
            int q = que_.front(); que_.pop();
            rep(i, 0, n){
                if(dist_[i] == -1 and g[q][i] != -1){
                    dist_[i] = dist_[q]+1;
                    que_.push(i);
                }
            }
        }
        ans[e] = dist_[n-1];
        g[s[e]][t[e]] = e;
    }

    rep(i, 0, m){
        cout << ans[i] << endl;
    }

    



    return 0;
}