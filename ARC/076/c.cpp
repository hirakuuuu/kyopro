#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int r, c, n; cin >> r >> c >> n;
    vector<vector<int>> x(n, vector<int>(2)), y(n, vector<int>(2));
    vector<vector<pair<int, int>>> order(4);
    rep(i, 0, n){
        cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
        if((x[i][0] == 0 || x[i][0] == r || y[i][0] == 0 || y[i][0] == c)
        && (x[i][1] == 0 || x[i][1] == r || y[i][1] == 0 || y[i][1] == c)){
            rep(j, 0, 2){
                if(x[i][j] == 0) order[0].push_back({y[i][j], i});
                else if(y[i][j] == c) order[1].push_back({x[i][j], i});
                else if(x[i][j] == r) order[2].push_back({y[i][j], i});
                else if(y[i][j] == 0) order[3].push_back({x[i][j], i});
            }
        }
    }

    rep(i, 0, 2) sort(order[i].begin(), order[i].end());
    rep(i, 2, 4) sort(order[i].rbegin(), order[i].rend());
    
    stack<int> stc;
    vector<int> in(n);
    rep(i, 0, 4){
        for(auto [_, j]: order[i]){
            if(in[j] && stc.top() != j){
                cout << "NO" << endl;
                return 0;
            }else if(in[j]){
                stc.pop();
                in[j] = 0;
            }else{
                stc.push(j);
                in[j] = 1;
            }
        }
    }
    cout << "YES" << endl;


    return 0;
}