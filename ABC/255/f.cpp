#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc255/tasks/abc255_f

int n, pos;
vector<int> p(200005), l(200005), pos_l(200005);
vector<int> lc(200005), rc(200005);

int rec(int L, int R){
    if(R <= L) return 0;
    int c = p[pos++];
    int m = pos_l[c];
    if(m < L or R < m) return -1;
    lc[c] = rec(L, m);
    rc[c] = rec(m+1, R);
    return c;
}




int main(){
    cin >> n;
    pos = 0;
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) cin >> l[i];
    rep(i, 0, n){
        pos_l[l[i]] = i;
    }

    if(p[0] != 1){
        cout << -1 << endl;
        return 0;
    }

    int a = rec(0, n);
    bool f = true;
    rep(i, 1, n+1){
        if(lc[i] == -1 or rc[i] == -1) f = false;
    }

    if(f){
        rep(i, 1, n+1){
            printf("%d %d\n", lc[i], rc[i]);
        }
    }else{
        cout << -1 << endl;
    }



    return 0;
}