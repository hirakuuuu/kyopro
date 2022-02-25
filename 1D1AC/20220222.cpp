#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
https://atcoder.jp/contests/abc196/tasks/abc196_d
h*w <= 16*16 より十分小さいので、愚直な全探索でいける
半畳は無視して、1畳をおけるパターンを全部考えれば良い
これはdfsでいける
*/

int H, W, A, B;
vector<vector<int>> used(16, vector<int>(16));

int dfs(int x, int y, int a){
    // 下まで到達したら、使い切った場合1足す
    if(y == H) return a==0;
    // 右まで到達したら、下にずれる
    if(x == W) return dfs(0, y+1, a);
    // すでに使われている場合、何もできないので次に進む
    if(used[y][x]) return dfs(x+1, y, a);

    int res = 0;

    // 縦置き
    if(y+1 < H and used[y+1][x] == 0 and 0 < a){
        used[y][x] = used[y+1][x] = 1;
        res += dfs(x+1, y, a-1);
        used[y][x] = used[y+1][x] = 0;
    }
    // 横置き
    if(x+1 < W and used[y][x+1] == 0 and 0 < a){
        used[y][x] = used[y][x+1] = 1;
        res += dfs(x+1, y, a-1);
        used[y][x] = used[y][x+1] = 0;
    }
    // 何もしない（半畳を置く）
    res += dfs(x+1, y, a);
    return res;
}

int main(){
    cin >> H >> W >> A >> B;
    cout <<  dfs(0, 0, A) << endl;
}