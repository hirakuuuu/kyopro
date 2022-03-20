#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n;cin >> n;
    string t; cin >> t;
    pii pos = {0, 0};
    int dir = 0;
    rep(i, 0, n){
        if(t[i] == 'S'){
            if(dir == 0) pos.first++;
            else if(dir == 1) pos.second--;
            else if(dir == 2) pos.first--;
            else pos.second++;
        }else dir = (dir+1)%4;
    }
    printf("%d %d\n", pos.first, pos.second);
  
}