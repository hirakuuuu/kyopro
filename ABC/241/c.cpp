#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
  int n; cin >> n;
  vector<vector<char>> s(n, vector<char>(n));
  rep(i, 0, n){
    rep(j, 0, n) cin >> s[i][j];
  }
  rep(i, 0, n){
  	rep(j, 0, n){
      // 横
      int cnt = 0;
      if(j+5 < n){
        rep(k, 0, 6){
            if(s[i][j+k] == '#') cnt++;
        }
      }
      if(cnt >= 4){
        cout << "Yes" << endl;
        return 0;
      }
      // 縦
      cnt = 0;
      if(i+5 < n){
        rep(k, 0, 6){
            if(s[i+k][j] == '#') cnt++;
        }
      }
      if(cnt >= 4){
        cout << "Yes" << endl;
        return 0;
      }
      // ななめ1
      cnt = 0;
      if(i+5 < n and j+5 < n){
        rep(k, 0, 6){
            if(s[i+k][j+k] == '#') cnt++;
        }
      }
      if(cnt >= 4){
        cout << "Yes" << endl;
        return 0;
      }
      // ななめ2
      cnt = 0;
      if(0 <= i-5 and j+5 < n){
        rep(k, 0, 6){
            if(s[i-k][j+k] == '#') cnt++;
        }
      }
      if(cnt >= 4){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}