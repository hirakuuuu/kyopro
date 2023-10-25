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
// https://atcoder.jp/contests/abc025/tasks/abc025_c

int b[5][5], c[5][5];
vector<int> a(9, 0);
int dfs(int t){
    int res = 0;
    if(t == 9){
        rep(i, 0, 2){
            rep(j, 0, 3){
                if(a[i*3+j] == a[(i+1)*3+j]) res += b[i][j];
                else res -= b[i][j];
            }
        }
        rep(i, 0, 3){
            rep(j, 0, 2){
                if(a[i*3+j] == a[i*3+j+1]) res += c[i][j];
                else res -= c[i][j];
            }
        }
        return res;
    }

    if(t%2 == 0) res = -IINF;
    else res = IINF;
    rep(i, 0, 9){
        if(a[i]) continue;
        a[i] = t%2+1;
        if(t%2 == 0) chmax(res, dfs(t+1));
        else chmin(res, dfs(t+1));
        a[i] = 0;
    }
    return res;
}

int main(){
    int sum = 0;
    rep(i, 0, 2){
        rep(j, 0, 3){
            cin >> b[i][j];
            sum += b[i][j];
        }
    }
    rep(i, 0, 3){
        rep(j, 0, 2){
            cin >> c[i][j];
            sum += c[i][j];
        }
    }

    int g = dfs(0);
    cout << (sum+g)/2 << endl;
    cout << (sum-g)/2 << endl;
    
    return 0;
}