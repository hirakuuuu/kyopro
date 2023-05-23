#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

ll MAX_D = (1LL<<32);

int main(){
    int v, e; cin >> v >> e;
    vector<vector<ll>> ans(v, vector<ll>(v, MAX_D));
    rep(i, 0, v) ans[i][i] = 0;
    rep(i, 0, e){
        int s, t, d; cin >> s >> t >> d;
        ans[s][t] = d;
    }

    rep(i, 0, v){
        rep(j, 0, v){
            if(ans[i][j] == MAX_D) cout << 'i';
            else cout << ans[i][j];
            cout << ' ';
        }
        cout << endl;
    }
    cout << endl;


    // ワーシャルフロイド法
    // ｋを中継点として1～ｋ-1までの頂点とi, jを通った最短経路と，1～ｋまでの頂点とi, jを通った最短経路とを比較
    // コストが小さい方を採用
    rep(k, 0, v){
        rep(i, 0, v){
            if(ans[i][k] == MAX_D) continue;
            rep(j, 0, v){
                if(ans[k][j] == MAX_D) continue;
                ans[i][j] = min(ans[i][j], ans[i][k]+ans[k][j]);
            }
        }
        rep(i, 0, v){
            rep(j, 0, v){
                if(ans[i][j] == MAX_D) cout << 'i';
                else cout << ans[i][j];
                cout << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // // 同じ頂点間でコストが負になっている場合
    // // 負の閉路が存在している
    // rep(i, 0, v){
    //     if(ans[i][i] < 0){
    //         cout << "NEGATIVE CYCLE" << endl;
    //         return 0;
    //     }
    // }

    rep(i, 0, v){
        rep(j, 0, v){
            if(j > 0) cout << " ";
            if(ans[i][j] == MAX_D) cout << "INF";
            else cout << ans[i][j];
        }
        cout << endl;
    }
  
}