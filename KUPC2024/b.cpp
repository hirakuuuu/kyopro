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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

vector<string> s = {
    ".@",
    "@.",
    ".@",
    "@.",
    ".@",
};

vector<string> t = {
    "..@..",
    "@....",
    "...@.",
    ".@...",
    "....@",
};

int main(){
    int T; cin >> T;
    while(T--){
        int a, b; cin >> a >> b;
        bool f = true;
        if(a > b){
            swap(a, b); 
            f = false;
        }
        if(a*4 < b){
            cout << -1 << endl;
            continue;
        }

        // s を 4a-b, t を b-a 個並べる
        vector<string> ans(5);
        // cout << 8*a-2*b << ' ' << 5*(b-a) << endl;
        rep(_, 0, 4*a-b){
            rep(i, 0, 5){
                ans[i] += s[i];
            }
        }
        rep(_, 0, b-a){
            rep(i, 0, 5){
                ans[i] += t[i];
            }
        }

        int h = 5, w = (int)ans[0].size();
        int cnt_b = 0, cnt_w = 0;
        rep(i, 0, h){
            rep(j, 0, w){
                if(ans[i][j] == '@') cnt_b++;
                else cnt_w++;
            }
        }
        // cout << cnt_b << ' ' << cnt_w << endl;

        cout << 5 << ' ' << ans[0].size() << endl;
        if(f){
            rep(i, 0, h){
                rep(j, 0, w){
                    if(ans[i][j] == '@') cout << '.';
                    else cout << '@';
                }
                cout << endl;
            }
        }else{
            rep(i, 0, h){
                cout << ans[i] << endl;
            }
        }
        
    }



    return 0;
}