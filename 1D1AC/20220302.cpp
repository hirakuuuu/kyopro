#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<int> par(200005, -1);
vector<int> nume(200005);
int root(int x){
    if(par[x] < 0) return x;
    return par[x] = root(par[x]);
}

bool same(int x, int y){
    return root(x) == root(y);
}

int size(int x){
    x = root(x);
    return (-1)*par[x];
}

void unite(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return;
    if(size(x) < size(y)) swap(x, y);
    par[x] += par[y];
    par[y] = x;
    nume[x]++;
    nume[x] += nume[y];
}

int num_edge(int x){
    if(par[x] < 0) return nume[x];
    return nume[x] = num_edge(par[x]);
}

int main(){
  int n, m; cin >> n >> m;

  rep(i, 0, m){
      int x, y; cin >> x >> y;
      if(!same(x, y)) unite(x, y);
      else nume[root(x)]++;
  }
  if(n != m){
      cout << 0 << endl;
      return 0;
  }
  map<int, int> r;
  ll ans = 1;
  rep(i, 1, n+1){
      int ri = root(i);
      if(r[ri]) continue;
      r[ri] = 1;
      if(size(ri) != num_edge(ri)){
          cout << 0 << endl;
          return 0;
      }
      ans = (ans*2)%mod;
  }
  cout << ans << endl;

}