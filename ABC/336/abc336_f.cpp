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
// https://atcoder.jp/contests/abc336/tasks/abc336_f

int h, w;
vector<vector<int>> rotate(vector<vector<int>> s, int t){
    vector<vector<int>> res = s;
    if(t == 0){
        rep(i, 0, h-1){
            rep(j, 0, w-1){
                res[i][j] = s[h-1-i-1][w-1-j-1];
            }
        }
    }else if(t == 1){
        rep(i, 1, h){
            rep(j, 0, w-1){
                res[i][j] = s[h-i][w-1-j-1];
            }
        }
    }else if(t == 2){
        rep(i, 0, h-1){
            rep(j, 1, w){
                res[i][j] = s[h-1-i-1][w-j];
            }
        }
    }else if(t == 3){
        rep(i, 1, h){
            rep(j, 1, w){
                res[i][j] = s[h-i][w-j];
            }
        }
    }
    return res;
}

int main(){
    cin >> h >> w;
    vector<vector<int>> s(h, vector<int>(w));
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> s[i][j];
            s[i][j]--;
        }
    }

    vector<vector<int>> t(h, vector<int>(w));
    rep(i, 0, h){
        rep(j, 0, w){
            t[i][j] = i*w+j;
        }
    }

    map<vector<vector<int>>, int> ds, dt;
    ds[s] = 1;
    queue<vector<vector<int>>> que;
    que.push(s);
    while(!que.empty()){
        vector<vector<int>> q = que.front(); que.pop();
        rep(i, 0, 4){
            vector<vector<int>> nq = rotate(q, i);
            if(ds[nq] == 0){
                ds[nq] = ds[q]+1;
                if(ds[nq] <= 10){
                    que.push(nq);
                }
            }
        }
    }
    dt[t] = 1;
    que.push(t);
    while(!que.empty()){
        vector<vector<int>> q = que.front(); que.pop();
        rep(i, 0, 4){
            vector<vector<int>> nq = rotate(q, i);
            if(dt[nq] == 0){
                dt[nq] = dt[q]+1;
                if(dt[nq] <= 10){
                    que.push(nq);
                }
            }
        }
    }

    int ans = IINF;
    for(auto [key, d]: ds){
        if(dt[key]){
            chmin(ans, ds[key]+dt[key]-2);
        }
    }

    if(ans == IINF) cout << -1 << endl;
    else cout << ans << endl;


    
    return 0;
}