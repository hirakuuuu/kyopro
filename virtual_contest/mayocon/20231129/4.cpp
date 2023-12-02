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
// 

int main(){
    int h, w; cin >> h >> w;
    vector<vector<char>> c(h+2, vector<char>(w+2, '#'));
    int sh, sw;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            cin >> c[i][j];
            if(c[i][j] == 'S'){
                sh = i;
                sw = j;
            }
        }
    }

    

    rep(k, 0, 4){
        int ch = sh+(k-1)%2, cw = sw+(k-2)%2;
        if(c[ch][cw] == '#') continue;
        queue<pair<int, int>> que;
        que.push({ch, cw});
        vector<vector<bool>> seen(h+2, vector<bool>(w+2));
        seen[ch][cw] = true;
        while(!que.empty()){
            auto [ph, pw] = que.front(); que.pop();
            rep(i, 0, 4){
                int nh = ph+(i-1)%2, nw = pw+(i-2)%2;
                if(c[nh][nw] == '#' || c[nh][nw] == 'S' || seen[nh][nw]) continue;
                seen[nh][nw] = true;
                que.push({nh, nw});
            }
        }

        rep(i, 0, 4){
            if(i == k) continue;
            int nh = sh+(i-1)%2, nw = sw+(i-2)%2;
            if(seen[nh][nw]){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;


    
    return 0;
}