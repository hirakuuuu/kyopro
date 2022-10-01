#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_i

int h, w, n;
vector<vector<int>> sekisetsu(1505, vector<int>(1505));

int main(){
    cin >> h >> w >> n;

    int a, b, c, d;
    rep(i, 0, n){
        cin >> a >> b >> c >> d;
        sekisetsu[a][b]++;
        sekisetsu[a][d+1]--;
        sekisetsu[c+1][b]--;
        sekisetsu[c+1][d+1]++;
    }

    rep(i, 1, h+1){
        rep(j, 1, w+1){
            sekisetsu[i][j] += sekisetsu[i][j-1];
        }
    }

    rep(i, 1, h+1){
        rep(j, 1, w+1){
            sekisetsu[i][j] += sekisetsu[i-1][j];
        }
    }

    rep(i, 1, h+1){
        rep(j, 1, w+1){
            if(j > 1) cout << ' ';
            cout << sekisetsu[i][j];
        }
        cout << endl;
    }
    
    return 0;
}