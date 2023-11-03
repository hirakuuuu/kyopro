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
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> ans;
    rep(i, 0, h){
        rep(j, 0, w){
            if(i == h-1 && j == w-1) continue;
            if(a[i][j]%2){
                if(i == h-1){
                    ans.push_back({i, j, i, j+1});
                    a[i][j+1]++;
                }else{
                    ans.push_back({i, j, i+1, j});
                    a[i+1][j]++;
                }
            }
        }
    }

    cout << ans.size() << endl;
    for(auto aa: ans){
        cout << aa[0]+1;
        rep(j, 1, 4){
            cout << ' ' << aa[j]+1;
        }
        cout << endl;
    }


    
    return 0;
}