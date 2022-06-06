#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

int main(int argc, char *argv[]) {
  // このコードは標準入力と標準出力を用いたサンプルコードです。
  // このコードは好きなように編集・削除してもらって構いません。
  // ---
  // This is a sample code to use stdin and stdout.
  // Edit and remove this code as you like.

  long long a, b, n; cin >> a >> b >> n;

  vector<long long> point(19);
  point[0] = a;
  int i = 0;
  while(true){
    point[i+1] = point[i]*10+pow(10, i)*(a+b);
    if(point[i+1] >= n) break;
    i++;
  }
  n -= point[i];
  long long ans = pow(10, i)-1;

  while(i >= 0 and n){
    int j = 1;
    while(j < 10){
      if(j != 7){
        if(n >= point[i]){
          n -= point[i];
        }else{
          break;
        }
      }else{
        if(n >= (a+b)*pow(10, i)){
          n -= (a+b)*pow(10, i);
        }else{
          break;
        }
      }
      j++;
    }
    ans += j*pow(10, i);
    i--;
  }
  cout << ans << endl;

  return 0;
}
