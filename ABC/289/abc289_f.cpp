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
// https://atcoder.jp/contests/abc289/tasks/abc289_f

int main(){
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    int a, b, c, d; cin >> a >> b >> c >> d;

    if(abs(sx-tx)%2 || abs(sy-ty)%2){
        cout << "No" << endl;
        return 0;
    }
    if(sx == tx && sy == ty){
        cout << "Yes" << endl;
        return 0;
    }
    if(a == b && c == d){
        if(2*a-sx == tx && 2*c-sy == ty){
            cout << "Yes" << endl;
            cout << a << ' ' << c << endl;
        }else{
            cout << "No" << endl;
        }
        return 0;
    }

    vector<pair<int, int>> ans;
    if(a == b){
        if(sx != tx && 2*a-sx != tx){
            cout << "No" << endl;
            return 0;
        }
        if(2*a-sx == tx){
            ans.push_back({a, c});
            sx = 2*a-sx;
            sy = 2*c-sy;
        }
        // y軸揃える
        int cnt_y = abs(sy-ty)/2;
        rep(i, 0, cnt_y){
            if(sy < ty){
                ans.push_back({a, c});
                ans.push_back({a, c+1});
            }else{
                ans.push_back({a, c+1});
                ans.push_back({a, c});
            }
        }
    }else if(c == d){
        if(sy != ty && 2*c-sy != ty){
            cout << "No" << endl;
            return 0;
        }
        if(2*c-sy == ty){
            ans.push_back({a, c});
            sx = 2*a-sx;
            sy = 2*c-sy;
        }
        // x軸揃える
        int cnt_x = abs(sx-tx)/2;
        rep(i, 0, cnt_x){
            if(sx < tx){
                ans.push_back({a, c});
                ans.push_back({a+1, c});
            }else{
                ans.push_back({a+1, c});
                ans.push_back({a, c});
            }
        }
    }else{
        // x軸揃える
        int cnt_x = abs(sx-tx)/2;
        rep(i, 0, cnt_x){
            if(sx < tx){
                ans.push_back({a, c});
                ans.push_back({a+1, c});
            }else{
                ans.push_back({a+1, c});
                ans.push_back({a, c});
            }
        }
        // y軸揃える
        int cnt_y = abs(sy-ty)/2;
        rep(i, 0, cnt_y){
            if(sy < ty){
                ans.push_back({a, c});
                ans.push_back({a, c+1});
            }else{
                ans.push_back({a, c+1});
                ans.push_back({a, c});
            }
        }
    }


    cout << "Yes" << endl;
    for(auto aa: ans){
        cout << aa.first << ' ' << aa.second << endl;
    }
    return 0;
}