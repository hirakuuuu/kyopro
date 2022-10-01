#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ch

int n; 
vector<vector<int>> papers(1505, vector<int>(1505));

int main(){
    cin >> n;

    int a, b, c, d;
    rep(i, 0, n){
        cin >> a >> b >> c >> d;
        papers[a][b]++;
        papers[a][d]--;
        papers[c][b]--;
        papers[c][d]++;
    }

    rep(i, 1, 1505){
        rep(j, 0, 1505){
            papers[i][j] += papers[i-1][j];
        }
    }
    rep(i, 0, 1505){
        rep(j, 1, 1505){
            papers[i][j] += papers[i][j-1];
        }
    }

    int ans = 0;
    rep(i, 0, 1505){
        rep(j, 0, 1505){
            if(papers[i][j] > 0) ans++;
        }
    }

    cout << ans << endl;
    
    
    return 0;
}