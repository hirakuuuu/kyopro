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
// https://atcoder.jp/contests/abc209/tasks/abc209_e

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    map<string, int> id;
    string abc;
    rep(i, 0, 26) abc += (char)('a'+i);
    rep(i, 0, 26) abc += (char)('A'+i);
    rep(i, 0, 52){
        rep(j, 0, 52){
            rep(k, 0, 52){
                string t = {abc[i], abc[j], abc[k]};
                id[t] = 52*52*i+52*j+k;
            }
        }
    }

    int m = 52*52*52;
    vector<vector<int>> g(m), rev_g(m);
    vector<int> deg(m);
    rep(i, 0, n){
        string L = s[i].substr(0, 3), R = s[i].substr(s[i].size()-3);
        int l = id[L], r = id[R];
        g[l].push_back(r);
        rev_g[r].push_back(l);
        deg[l]++;
    }
    queue<int> que;
    vector<int> win(m, -1), seen(m);

    rep(i, 0, m){
        if(deg[i] == 0){
            que.push(i);
            seen[i] = 1;
        }
    }
    while(!que.empty()){
        int q = que.front(); que.pop();
        bool f = false;
        for(auto c: g[q]){
            if(win[c] == 1) f = true;
        }
        if(f) win[q] = 0;
        else win[q] = 1;

        if(win[q] == 1){
            for(auto nq: rev_g[q]){
                if(!seen[nq]){
                    que.push(nq);
                    seen[nq] = 1;
                }
            }
        }else{
            for(auto nq: rev_g[q]){
                deg[nq]--;
                if(!seen[nq] && deg[nq] == 0){
                    seen[nq] = 1;
                    que.push(nq);
                }
            }
        }
    }    

    rep(i, 0, n){
        int j = id[s[i].substr(s[i].size()-3)];
        if(win[j] == 1) cout << "Takahashi" << endl;
        else if(win[j] == 0) cout << "Aoki" << endl;
        else cout << "Draw" << endl;
    }
    

    return 0;
}