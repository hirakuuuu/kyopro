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

/*
グリッドを円環とみなす（偶数×偶数ならハミルトンパスが取れるからいける）
*/

int main(){
    int t; cin >> t;
    while(t--){
        int h, w; cin >> h >> w;
        vector<string> s(2*h);
        vector<vector<int>> a(2*h, vector<int>(2*w));
        rep(i, 0, 2*h){
            cin >> s[i];
            rep(j, 0, 2*w){
                if(s[i][j] == 'o') a[i][j] = 1;
            }
        }

        vector<pair<int, int>> path = {{0, 0}};
        rep(i, 0, w){
            rep(j, 1, 2*h){
                path.push_back({j, 2*i});
            }
            rrep(j, 2*h-1, 1){
                path.push_back({j, 2*i+1});
            }
        }
        rrep(i, 2*w-1, 1){
            path.push_back({0, i});
        }
        assert(path.size() == 4*h*w);

        vector<int> acc(4*h*w+1);
        rep(i, 0, 4*h*w){
            acc[i+1] = acc[i]+a[path[i].first][path[i].second];
            // cout << path[i].first << ' ' << path[i].second << ' ' << acc[i+1] << endl;
        }
        vector<string> ans(2*h, string(2*w, 'B'));
        rep(i, 0, 2*h*w+1){
            if(acc[i+2*h*w]-acc[i] == h*w){
                rep(j, i, i+2*h*w){
                    ans[path[j].first][path[j].second] = 'A';
                }
                break;
            }
        }

        rep(i, 0, 2*h){
            cout << ans[i] << endl;
        }
        
    }
    
    return 0;
}