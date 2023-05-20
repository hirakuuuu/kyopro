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
// https://atcoder.jp/contests/abc302/tasks/abc302_f

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> s(n);
    vector<vector<int>> cnt(m+1);

    queue<pii> que;
    vector<int> dist(n,IINF);
    vector<bool> seen(n), seen_num(m+1);
    rep(i, 0, n){
        cin >> a[i];
        s[i].resize(a[i]);
        rep(j, 0, a[i]){
            cin >> s[i][j];
            cnt[s[i][j]].push_back(i);
        }
    }

    rep(i, 0, n){
        bool f = false;
        rep(j, 0, a[i]){
            if(s[i][j] == 1) f = true;
        }

        if(f){
            rep(j, 0, a[i]){
                que.push({s[i][j], i});
            }
            dist[i] = 0;
            seen[i] = true;
            seen_num[1] = true;
        }
    }


    while(!que.empty()){
        pii q = que.front(); que.pop();
        int num = q.first, pos = q.second;
        for(auto npos: cnt[num]){
            if(seen[npos]) continue;
            rep(i, 0, a[npos]){
                if(seen_num[s[npos][i]]) continue;
                seen_num[s[npos][i]] = true;
                que.push({s[npos][i], npos});
            }
            seen[npos] = true;
            dist[npos] = dist[pos]+1;
        }
    }

    int ans = IINF;
    for(auto nq: cnt[m]){
        chmin(ans, dist[nq]);
    }
    // rep(i, 0, n){
    //     cout << dist[i] << endl;
    // }

    if(ans == IINF) cout << -1 << endl;
    else cout << ans << endl;


    
    return 0;
}