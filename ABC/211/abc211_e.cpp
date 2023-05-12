#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc211/tasks/abc211_e

/*
k個の連結なマスの組を全て列挙→DFS
各組に黒色のマスが含まれているかを調べる
*/

vector<string> s(10);
int n, k, ans = 0;

bool valid(int x, int y){
    return (0 <= x and x < n and 0 <= y and y < n);
}

void dfs(int num){

    if(num == 0){
        ans++;
        return;
    }

    vector<pii> next;
    rep(i, 0, n){
        rep(j, 0, n){
            if(s[i][j] == '.'){
                bool f = false;
                rep(l, 0, 4){
                    int nx = i+(l-1)%2, ny = j+(l-2)%2;
                    if(valid(nx, ny) and s[nx][ny] == '@'){
                        f = true;
                    }
                }
                if(f){
                    s[i][j] = '@';
                    next.push_back({i, j});
                    dfs(num-1);
                    s[i][j] = '#';
                }
            }
        }
    }

    for(auto nx: next){
        s[nx.first][nx.second] = '.';
    }
}

int main(){
    cin >> n >> k;
    rep(i, 0, n) cin >> s[i];
    ans = 0;
    rep(i, 0, n){
        rep(j, 0, n){
            if(s[i][j] == '.'){
                s[i][j] = '@';
                dfs(k-1);
                s[i][j] = '#';
            }
        }
    }
    dfs(k);
    cout << ans << endl;


    
    return 0;
}