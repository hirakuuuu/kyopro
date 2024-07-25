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
    vector<int> s(2), t(2);
    rep(i, 0, 2) cin >> s[i];
    rep(i, 0, 2) cin >> t[i];
    int a, b, c, d; cin >> a >> b >> c >> d;

    // 偶奇が異なるなら NO
    rep(i, 0, 2) if(s[i]%2 != t[i]%2){
        cout << "No" << endl;
        return 0;
    }
    
    vector<pair<int, int>> ans;
    // 点を移動させる
    auto move = [&](int &sx, int &sy, int rx, int ry) -> void {
        sx = 2*rx-sx;
        sy = 2*ry-sy;
    };
    // x 座標を変えずに, y 座標を合わせる
    auto adjust_y = [&](int sy, int ty) -> void {
        int dist = abs(sy-ty);
        assert(dist%2 == 0);
        assert(c < d);
        if(sy > ty){
            rep(i, 0, dist/2){
                ans.push_back({a, d});
                ans.push_back({a, d-1});
            }
        }
        if(sy < ty){
            rep(i, 0, dist/2){
                ans.push_back({a, c});
                ans.push_back({a, c+1});
            }
        }
    };
    // y 座標を変えずに, x 座標を合わせる
    auto adjust_x = [&](int sx, int tx) -> void {
        int dist = abs(sx-tx);
        assert(dist%2 == 0);
        assert(a < b);
        if(sx > tx){
            rep(i, 0, dist/2){
                ans.push_back({b, c});
                ans.push_back({b-1, c});
            }
        }
        if(sx < tx){
            rep(i, 0, dist/2){
                ans.push_back({a, c});
                ans.push_back({a+1, c});
            }
        }
    };

    if(s[0] != t[0] || s[1] != t[1]){
        if(a == b && c == d){
            move(s[0], s[1], a, c);
            if(s[0] == t[0] && s[1] == t[1]){
                ans.push_back({a, c});
            }else{
                cout << "No" << endl;
                return 0;
            }
        }else if(a == b){
            if(s[0] == t[0]){
                adjust_y(s[1], t[1]);
            }else{
                move(s[0], s[1], a, c);
                if(s[0] == t[0]){
                    ans.push_back({a, c});
                    adjust_y(s[1], t[1]);
                }else{
                    cout << "No" << endl;
                    return 0;
                }
            }
        }else if(c == d){
            if(s[1] == t[1]){
                adjust_x(s[0], t[0]);
            }else{
                move(s[0], s[1], a, c);
                if(s[1] == t[1]){
                    ans.push_back({a, c});
                    adjust_x(s[0], t[0]);
                }else{
                    cout << "No" << endl;
                    return 0;
                }
            }
        }else{
            adjust_x(s[0], t[0]);
            adjust_y(s[1], t[1]);
        }
    }
    cout << "Yes" << endl;
    for(auto [rx, ry]: ans){
        cout << rx << ' ' << ry << endl;
    }



    
    return 0;
}