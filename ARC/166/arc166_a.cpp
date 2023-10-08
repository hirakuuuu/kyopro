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
// https://atcoder.jp/contests/arc166/tasks/arc166_a

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string x, y; cin >> x >> y;
        bool f = true;
        for(int i = 0; i < n; i++){
            string cx, cy;
            while(i < n && y[i] != 'C'){
                cx += x[i];
                cy += y[i];
                i++;
            }
            // yでcである箇所で、ｘがcでない
            if(i < n && y[i] == 'C' && x[i] != 'C'){
                f = false;
                break;
            }
            // cx, cyのa,bの個数について
            vector<vector<int>> cnt_x(3), cnt_y(3);
            rep(j, 0, cx.size()){
                cnt_x[cx[j]-'A'].push_back(j);
                cnt_y[cy[j]-'A'].push_back(j);
            }

            int ind = 0;
            rep(j, 0, 2){
                if(cnt_x[j].size() > cnt_y[j].size()){
                    f = false;
                    break;
                }
            }
            if(!f) break;


            rep(j, 0, 2){
                int tmp = cnt_y[j].size() - cnt_x[j].size();
                //if(tmp > cnt_x[2].size()-ind) return 0;
                rep(_, 0, tmp){
                    cnt_x[j].push_back(cnt_x[2][ind]);
                    ind++;
                }
                sort(cnt_x[j].begin(), cnt_x[j].end());
            }

            rep(j, 0, cnt_x[1].size()){
                if(cnt_x[1][j] < cnt_y[1][j]) f = false;
            }
        }

        if(f) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}