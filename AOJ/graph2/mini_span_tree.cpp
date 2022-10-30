#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

//プリムのアルゴリズム

int n;
vector<vector<int>> m(105, vector<int>(105));
vector<int> c(105, 0), p(105, -1), d(105, MOD);

int prim(){
    d[0] = 0;
    while(true){
        int minc = MOD, u = -1;
        rep(i, 0, n){
            if(c[i] != 2 and d[i] < minc){
                minc = d[i];
                u = i;
            }
        }
        if(u == -1) break;

        c[u] = 2;

        rep(i, 0, n){
            if(c[i] != 2 and m[u][i] >= 0){
                if(m[u][i] < d[i]){
                    d[i] = m[u][i];
                    p[i] = u;
                    c[i] = 1;
                }
            }
        }
    }

    int sum = 0;
    rep(i, 0, n){
        if(p[i] != -1) sum += m[i][p[i]];
    }
    return sum;
}

int main(){
    cin >> n;
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> m[i][j];
        }
    }
    cout << prim() << endl;
}