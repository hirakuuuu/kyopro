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
    int h, w; cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    vector<vector<int>> cnt_h(h, vector<int>(26)), cnt_w(w, vector<int>(26));
    vector<bool> seen_h(h), seen_w(w);
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> c[i][j];
            cnt_h[i][c[i][j]-'a']++;
            cnt_w[j][c[i][j]-'a']++;
        }
    }

    queue<pair<int, int>> que;
    rep(i, 0, h){
        int k = 0, p = 0;
        rep(j, 0, 26){
            if(cnt_h[i][j]){
                k++;
                p = j;
            }
        }
        if(k == 1){
            cnt_h[i][p] = 0;
            que.push({i, p});
            seen_h[i] = true;
        }
    }
    rep(i, 0, w){
        int k = 0, p = 0;
        rep(j, 0, 26){
            if(cnt_w[i][j]){
                k++;
                p = j;
            }
        }
        if(k == 1){
            cnt_w[i][p] = 0;
            que.push({3000+i, p});
            seen_w[i] = true;
        }
    }


    while(!que.empty()){
        auto [id, tmp] = que.front(); que.pop();
        if(id < 3000){
            rep(i, 0, w){
                if(c[id][i]-'a' == tmp && cnt_w[i][tmp]) cnt_w[i][tmp]--;
            }
            rep(i, 0, w){
                if(seen_w[i]) continue;
                int k = 0, p = 0, sum = 0;
                rep(j, 0, 26){
                    if(cnt_w[i][j]){
                        k++;
                        p = j;
                        sum += cnt_w[i][j];
                    }
                }
                if(k == 1 && sum >= 2){
                    cnt_w[i][p] = 0;
                    seen_w[i] = true;
                    que.push({3000+i, p});
                }
            }
        }else{
            id -= 3000;
            rep(i, 0, h){
                if(c[i][id]-'a' == tmp && cnt_h[i][tmp]) cnt_h[i][tmp]--;
            }
            rep(i, 0, h){
                if(seen_h[i]) continue;
                int k = 0, p = 0, sum = 0;
                rep(j, 0, 26){
                    if(cnt_h[i][j]){
                        k++;
                        p = j;
                        sum += cnt_h[i][j];
                    }
                }
                if(k == 1 && sum >= 2){
                    cnt_h[i][p] = 0;
                    seen_h[i] = true;
                    que.push({i, p});
                }
            }
        }

    }

    int ans = 0;
    rep(i, 0, h){
        rep(j, 0, 26){
            ans += cnt_h[i][j];
        }
    }
    cout << ans << endl;



    
    return 0;
}