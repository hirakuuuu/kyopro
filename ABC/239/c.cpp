#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
  ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  vector<int> dx = {1, 2, -1, -2, 1, 2, -1, -2};
  vector<int> dy = {2, 1, 2, 1, -2, -1, -2, -1};
  rep(i, 0, 8){
    double dist = sqrt((x1+dx[i]-x2)*(x1+dx[i]-x2)+(y1+dy[i]-y2)*(y1+dy[i]-y2));
    if(dist == sqrt(5)){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;   
}