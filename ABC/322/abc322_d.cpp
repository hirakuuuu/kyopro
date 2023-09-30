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
// https://atcoder.jp/contests/abc322/tasks/abc322_d

int main(){
    vector<vector<vector<int>>> p(3, vector<vector<int>>(4, vector<int>(4)));
    vector<pair<int, int>> q(3, {-1, -1});
    vector<vector<vector<pair<int, int>>>> r(4, vector<vector<pair<int, int>>>(3));
    int cnt = 0;
    rep(i, 0, 3){
        rep(j, 0, 4){
            rep(k, 0, 4){
                char c; cin >> c;
                if(c == '#'){
                    p[i][j][k] = 1;
                    cnt++;
                    if(q[i] == make_pair(-1, -1)) q[i] = {j, k};
                    r[0][i].emplace_back(j-q[i].first, k-q[i].second);
                    r[1][i].emplace_back(-(k-q[i].second), j-q[i].first);
                    r[2][i].emplace_back(-(j-q[i].first), -(k-q[i].second));
                    r[3][i].emplace_back(k-q[i].second, -(j-q[i].first));
                }
            }
        }
    }

    rep(i, 0, 48){
        rep(j, 0, 48){
            rep(k, 0, 48){
                set<pair<int, int>> s;
                vector<int> rotate = {i/16, j/16, k/16};
                vector<pair<int, int>> pos = {{(i%16)/4, i%4}, {(j%16)/4, j%4}, {(k%16)/4, k%4}};
                rep(l, 0, 3){
                    int x = pos[l].first, y = pos[l].second;
                    for(auto rr: r[rotate[l]][l]){
                        int nx = x+rr.first, ny = y+rr.second;
                        if(nx < 0 || 3 < nx || ny < 0 || 3 < ny) continue;
                        s.insert({nx, ny});
                    }
                }

                if(cnt == 16 && s.size() == 16){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}