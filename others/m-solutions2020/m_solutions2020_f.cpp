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
// https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_f

int main(){
    int n; cin >> n;
    vector<tuple<int, int, char>> xy(n);
    vector<char> d(n);
    rep(i, 0, n){
        int X, Y;
        char D; cin >> X >> Y >> D;
        xy[i] = {X, Y, D};
    }
    sort(xy.begin(), xy.end());
    vector<int> x(n), y(n);
    vector<vector<int>> Dy(200005);
    vector<vector<int>> Lx(200005);

    vector<vector<int>> Lyxmy(400005);
    vector<vector<int>> Ryxpy(400005);
    vector<vector<int>> Ryxmy(400005);
    vector<vector<int>> Lyxpy(400005);

    rep(i, 0, n){
        tie(x[i], y[i], d[i]) = xy[i];
        if(d[i] == 'D') Dy[x[i]].push_back(y[i]);
        if(d[i] == 'L') Lx[y[i]].push_back(x[i]);

        // if(d[i] == 'D') Dxxmy[x[i]-y[i]+200000].push_back(x[i]);
        // if(d[i] == 'U') Uxxpy[x[i]+y[i]].push_back(x[i]);
        if(d[i] == 'L'){
            Lyxmy[x[i]-y[i]+200000].push_back(y[i]);
            Lyxpy[x[i]+y[i]].push_back(y[i]);
        }
        if(d[i] == 'R'){
            Ryxpy[x[i]+y[i]].push_back(y[i]);
            Ryxmy[x[i]-y[i]+200000].push_back(y[i]);
        }
    }

    int ans = IINF;
    rep(i, 0, n){
        
        if(d[i] == 'U'){
            // UとDの衝突
            auto itr = upper_bound(Dy[x[i]].begin(), Dy[x[i]].end(), y[i]);
            if(itr != Dy[x[i]].end()) chmin(ans, (*itr-y[i])*5);

            // UとLの衝突
            itr = upper_bound(Lyxmy[x[i]-y[i]+200000].begin(), Lyxmy[x[i]-y[i]+200000].end(), y[i]);
            if(itr != Lyxmy[x[i]-y[i]+200000].end()) chmin(ans, (*itr-y[i])*10);

            // UとRの衝突
            itr = upper_bound(Ryxpy[x[i]+y[i]].begin(), Ryxpy[x[i]+y[i]].end(), y[i]);
            if(itr != Ryxpy[x[i]+y[i]].end()) chmin(ans, (*itr-y[i])*10);
        }
        // LとRの衝突
        if(d[i] == 'R'){
            auto itr = upper_bound(Lx[y[i]].begin(), Lx[y[i]].end(), x[i]);
            if(itr != Lx[y[i]].end()) chmin(ans, (*itr-x[i])*5);
        }

        if(d[i] == 'D'){
            // DとRの衝突
            auto itr = lower_bound(Ryxmy[x[i]-y[i]+200000].begin(), Ryxmy[x[i]-y[i]+200000].end(), y[i]);
            if(itr != Ryxmy[x[i]-y[i]+200000].begin()){
                itr--;
                chmin(ans, (y[i]-*itr)*10);
            }

            // DとLの衝突
            itr = lower_bound(Lyxpy[x[i]+y[i]].begin(), Lyxpy[x[i]+y[i]].end(), y[i]);
            if(itr !=  Lyxpy[x[i]+y[i]].begin()){
                itr--;
                chmin(ans, (y[i]-*itr)*10);
            }
        }
    }

    if(ans != IINF) cout << ans << endl;
    else cout << "SAFE" << endl;
    
    return 0;
}