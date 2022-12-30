#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc196/tasks/abc196_d

vector<vector<bool>> used(100, vector<bool>(100));

bool check(int i, int j, int h, int w){
    return (0 <= i and i < h and 0 <= j and j < w);
}

int dfs(int h, int w, int a, int d){
    int res = 0;
    if(d == a){
        return 1;
    }
    rep(i, 0, h){
        rep(j, 0, w){
            if(!used[i][j] and check(i+1, j, h, w) and !used[i+1][j]){
                used[i][j] = used[i+1][j] = true;
                res += dfs(h, w, a, d+1);
                used[i][j] = used[i+1][j] = false;
            }
            
            if(!used[i][j] and check(i, j+1, h, w) and !used[i][j+1]){
                used[i][j] = used[i][j+1] = true;
                res += dfs(h, w, a, d+1);
                used[i][j] = used[i][j+1] = false;
            }
        }
    }
    return res;
}

int main(){
    int h, w, a, b; cin >> h >> w >> a >> b;
    int f = 1;
    rep(i, 1, a+1) f *= i;
    cout << dfs(h, w, a, 0)/f << endl;


    
    return 0;
}