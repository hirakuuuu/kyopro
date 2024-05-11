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
    vector<vector<pair<int, int>>> p(3);
    rep(i, 0, 3){
        rep(j, 0, 4){
            rep(k, 0, 4){
                char c; cin >> c;
                if(c == '#') p[i].push_back({j, k});
            }
        }
    }
    if(p[0].size()+p[1].size()+p[2].size() != 16){
        cout << "No" << endl;
        return 0;
    }
    auto rotate = [&](int i) -> void{
        rep(j, 0, p[i].size()){
            auto [x, y] = p[i][j];
            p[i][j] = {3-y, x};
        }
    };
    auto judge = [&](vector<int> sx, vector<int> sy) -> bool {
        set<int> s;
        bool ok = true;
        rep(i, 0, 3){
            int mx = p[i][0].first-sx[i], my = p[i][0].second-sy[i];
            rep(j, 0, p[i].size()){
                int ni = p[i][j].first-mx, nj = p[i][j].second-my;
                if(!inr(0, ni, 4) || !inr(0, nj, 4)) ok = false;
                else s.insert(ni*4+nj);
            }
        }
        // for(auto ss: s){
        //     cout << ss << ' ';
        // }
        // cout << endl;
        if(ok && s.size() == 16) return true;
        return false;
    };
    rep(_, 0, 4){
        rep(__, 0, 4){
            rep(___, 0, 4){
                rep(i, 0, 16){
                    rep(j, 0, 16){
                        rep(k, 0, 16){
                            vector<int> x = {i/4, j/4, k/4};
                            vector<int> y = {i%4, j%4, k%4};
                            if(judge(x, y)){
                                cout << "Yes" << endl;
                                return 0;
                            }
                        }
                    }
                }

                rotate(2);
            }
            rotate(1);
        }
        rotate(0);
    }
    cout << "No" << endl;
    return 0;
}