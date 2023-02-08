#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_l

/*
連結の判定はunion-find木
・タスク1では上下左右に赤いますがあればそれと連結
・タスク2では与えられた2マスが連結であるかどうかで判定できる
・マスを1次元で表してみたがこれが良い方法なのかは分からない
*/

vector<int> par(4000005, -1);

int root(int x){
    if(par[x] < 0) return x;
    else return par[x] = root(par[x]);
}

bool same(int x, int y){
    return root(x) == root(y);
}

void unite(int x, int y){
    x = root(x), y = root(y);
    if(x == y) return;
    if(par[x] < par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int main(){
    int h, w; cin >> h >> w;
    vector<int> col(4000005, 0);
    int q; cin >> q;
    vector<int> d = {1, -1, w, -w};
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int r, c; cin >> r >> c;
            int pos = w*(r-1)+c;
            col[pos] = 1;
            rep(i, 0, 4){
                if(i == 0 and c == w) continue;
                if(i == 1 and c == 1) continue;
                int npos = pos+d[i];
                if(0 < npos and npos <= h*w and col[npos]){
                    unite(pos, npos);
                }
            }
        }else{
            int ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb;
            int A = w*(ra-1)+ca, B = w*(rb-1)+cb;
            if(col[A] and col[B] and same(A, B)) cout << "Yes" << endl;
            else cout << "No" << endl; 
        }
    }
    return 0;
}